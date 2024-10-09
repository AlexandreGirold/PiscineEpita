#!/bin/bash

evaluate() {
    echo "$(( $1 ))"
}


if [ $# -gt 0 ]; then
    evaluate "$1"
    exit 0
fi


while read -r expression; do
    [ -z "$expression" ] && break
    evaluate "$expression"
done
