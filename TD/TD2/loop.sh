#!/bin/sh
echo "loop 1"


for i in e1 e2; do
        echo "$i"
done

echo "loop 2"

for e in $(seq 3 7); do 
        echo "Your time: $e"
done

for arg; do
        echo "$arg"
done
