#!/bin/sh

for i in *.sh; do
        echo "$i"
done

case "${1}" in 
        *.sh)
                echo It is a shell file;;
        *)
                echo different extension;;
esac
