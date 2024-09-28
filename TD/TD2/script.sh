#!/bin/sh

for file; do 
        [ -x "$file" ] && echo "$file" || echo "not exevutable chnage permissions"
done
