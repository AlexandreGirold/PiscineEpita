#!/bin/sh

s=$(("$1"%60))
m=$(("$1"/60))

if [ $s -lt 10 ]; then
        echo "$m":0"$s"
else
        echo "$m":"$s"
fi
