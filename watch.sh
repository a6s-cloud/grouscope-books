#!/usr/bin/env bash

IMAGE="a6scloud/grouscope-books"
TAG="latest"
#TAG="testing"

main() {
    local opt="$1"

    # このスクリプトがあるディレクトリに移動する
    cd "$( dirname "${BASH_SOURCE[0]}" )"

    if [[ "$opt" == "-d" ]]; then
        docker run --rm --name grouscope_books \
                --volume "${PWD}:/root/grouscope-books" -d ${IMAGE}:${TAG}
    else
        docker run --rm --name grouscope_books \
                --volume "${PWD}:/root/grouscope-books" -ti ${IMAGE}:${TAG}
    fi
}

main "$@"
