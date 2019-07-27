#!/usr/bin/env bash

WORK_DIR="/root/grouscope-books"
DESTINATION="mybook.pdf"

main() {

    cd "$WORK_DIR"
    if [[ ! -f "$DESTINATION" ]]; then
        rake pdf
        echo "$(date +%Y%m%d %H:%M:%S) 初期ファイルを作成しました"
    fi

    declare -A last_files_of_stats

    # ファイルキャッシュリストを作成する
    local file
    while read file; do
        last_files_of_stats=true
    done < <(find . -name "*.re" -type f | sed -e 's|^\./||')

    local path
    local action
    local file
    local hash_value
    local last_hash_value
    local result_of_rake
    inotifywait -m /root/grouscope-books -e create -e move -e delete |
            while read path action file; do
                if [[ "$file" =~ .*\.re$ ]]; then
                    if [[ "$action" == "MOVED_FROM" ]] || [[ "$action" == "DELETE" ]]; then
                        [[ ! -f "$file" ]] && unset last_files_of_stats["$file"]
                    fi

                    hash_value="$(sha1sum "$file" | cut -d ' ' -f 1)"
                    #echo "Last_hash: ${last_files_of_stats["$file"]}, Current_hash: $hash_value, File: $file"
                    if [[ "${last_files_of_stats["$file"]}" != "$hash_value" ]]; then
                        echo "##### rake pdf -- File: $file, Action: $action"
                        last_hash_value="${last_files_of_stats["$file"]}"
                        last_files_of_stats["$file"]="$hash_value"
                        rake pdf
                        result_of_rake=$?
                        if [[ $result_of_rake -eq 0 ]]; then
                            echo "INFO: ビルドが成功しました[トリガ: File: $file, Action: $action, last_hash: ${last_hash_value:0:7}, current_hash: ${hash_value:0:7}]"
                        else
                            echo "ERROR: ビルドに失敗しました[トリガ: File: $file, Action: $action, last_hash: ${last_hash_value:0:7}, current_hash: ${hash_value:0:7}]" >&2
                        fi
                    fi
                fi
            done
}

main "$@"

