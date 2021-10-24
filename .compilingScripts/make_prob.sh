#!/usr/bin/env bash

DIR=$(dirname $0)
search_up ()
(
    while [[ $PWD != "/" ]]; do
        if [[ -e "$1" ]]; then
            pwd
            if [[ ! -e "$1/$2" ]]; then
                break
            fi
        fi
        cd ..
    done
)
TEMPLATE_DIR='.template'
PARENT_FILE='$PARENT'
IFS=$'\n'
TEMPLATE_DIRS=($(search_up "$TEMPLATE_DIR" "$PARENT_FILE" | tac))
unset IFS
TEMPLATE_DIRS=(${TEMPLATE_DIRS[@]/%/\/"$TEMPLATE_DIR"})

if hash rename.ul 2>/dev/null; then
    RENAME=rename.ul
else
    RENAME=rename
fi

for filepath in "$@"; do
    PROBLEM_NAME=main

    if [[ -e "$filepath" ]]; then
        echo "$filepath already exists. Remove it and retry."
        continue
    fi

    # Copy files in
    mkdir -p "$filepath"
    for CURRENT_TEMPLATE_DIR in "${TEMPLATE_DIRS[@]}"; do
        cp -r -T "$CURRENT_TEMPLATE_DIR" "$filepath/"
    done
    rm -f "$filepath/$PARENT_FILE"
    cat ~/comp_programming/code/template.cpp > ./$filepath/"$PROBLEM_NAME".cpp; echo "created '$PROBLEM_NAME'.cpp file"; 

    pushd $filepath > /dev/null
    if [[ -e "setup" ]]; then
        ./setup
    fi
    popd > /dev/null
done
