#!/bin/sh
for i in $(seq 5); do
        for j in $(seq 5); do
                for k in $(seq 5); do
                        if [ "$k" -gt 2 ]; then 
                                break 2
                        fi
                        echo "$i,$j,$k"
                done
         done
done
