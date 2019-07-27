#!/usr/bin/env bash

WORK_DIR="/root/grouscope-books"
DESTINATION="mybook.pdf"
EMOJI_POPPER="🎉"
EMOJI_SORROWLY="😱"
EMOJI_GLASS="🧐"

main() {

    cd "$WORK_DIR"

    rake pdf
    echo "$(date "+%Y/%m/%d %H:%M:%S") INFO: ${EMOJI_POPPER}初期ファイルを作成しました${EMOJI_POPPER} [File: ${DESTINATION}]"
    echo "$(date "+%Y/%m/%d %H:%M:%S") INFO: モニタリングを開始しました${EMOJI_GLASS}。Re:VIEW ファイルの追加/削除/変更を監視して自動でPDF ファイルを出力します"

    # ファイルキャッシュリストを作成する
    declare -A last_files_of_stats
    local file
    local hash_value
    while read file; do
        hash_value="$(sha1sum "$file" 2> /dev/null | cut -d ' ' -f 1)"
        last_files_of_stats["$file"]="$hash_value"
    done < <(find . -name "*.re" -type f | sed -e 's|^\./||')

    local path
    local action
    local last_hash_value
    local result_of_rake

    while read path action file; do
        # echo "File: $file, Action: $action"    # debug
        if [[ "$file" =~ .*\.re$ ]]; then
            last_hash_value="${last_files_of_stats["$file"]}"
            hash_value="$(sha1sum "$file" 2> /dev/null | cut -d ' ' -f 1)"

            if [[ "$action" == "MOVED_FROM" ]] || [[ "$action" == "DELETE" ]]; then
                [[ ! -f "$file" ]] && unset last_files_of_stats["$file"]
            fi

            # echo "Last_hash: $last_hash_value, Current_hash: $hash_value, File: $file"    # debug
            if [[ "$last_hash_value" != "$hash_value" ]]; then
                if [[ ! -z "$hash_value" ]]; then
                    last_files_of_stats["$file"]="$hash_value"
                fi

                echo "$(date "+%Y/%m/%d %H:%M:%S") INFO: rake pdf -- File: $file, Action: $action, Hash: ${hash_value:0:7}"
                rake pdf
                result_of_rake=$?
                echo "============================================================================="
                if [[ $result_of_rake -eq 0 ]]; then
                    echo "$(date "+%Y/%m/%d %H:%M:%S") INFO: ${EMOJI_POPPER}ビルドが成功しました${EMOJI_POPPER}[トリガ: File: $file, Action: $action, last_hash: ${last_hash_value:0:7}, current_hash: ${hash_value:0:7}, out: mybook.pdf]"
                else
                    echo "$(date "+%Y/%m/%d %H:%M:%S") ERROR: ${EMOJI_SORROWLY}ビルドに失敗しました${EMOJI_SORROWLY}[トリガ: File: $file, Action: $action, last_hash: ${last_hash_value:0:7}, current_hash: ${hash_value:0:7}]" >&2
                fi
                echo "============================================================================="
            fi
        fi
    done < <(inotifywait -m /root/grouscope-books -e create -e move -e delete -e modify)
}

main "$@"

