#!/bin/sh

while ! [ "$SECONDS" -eq $1 ]; do
        echo "$SECONDS" 
        if [ "$SECONDS" -gt 2 ]; then
        break 
        fi
done
