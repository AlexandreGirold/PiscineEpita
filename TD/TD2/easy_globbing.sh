#!/bin/sh

for file in "$1"/*; do
       case "$file" in
              *.[!0-9][!0-9])
                      echo "$file"
                      ;;
        esac
done
