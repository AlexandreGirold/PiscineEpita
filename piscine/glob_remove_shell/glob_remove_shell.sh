#!/bin/sh
if [ $# -eq 0 ]; then
    if ( set +f -- *.txt; test "$*" != '*.txt' || test -f '*.txt' ); then 
            for i in *.txt; do
                 rm "$i"
            done
    else
            exit 1
    fi
else
    for i in *.$1; do
            rm "$i"
    done
fi
