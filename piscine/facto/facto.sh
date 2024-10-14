#!/bin/bash

if [ "$#" -eq 0 ]; then
    echo "1"  # The factorial of 0 is 1
    exit 0
fi

factorial=1


for (( i=1; i<=$1; i++ )); do
    factorial=$(( factorial * i ))
done

echo "$factorial"
exit 0
