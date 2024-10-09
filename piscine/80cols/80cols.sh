#!/bin/sh

if [ "$#" -ne 1 ] || [ ! -r "$1" ]; then
    exit 1
fi


while IFS= read -r line; do
    # Check the length of the line
    if [ "${#line}" -gt 80 ]; then

        printf "%s\n" "$line"
    fi
done < "$1"

exit 0
