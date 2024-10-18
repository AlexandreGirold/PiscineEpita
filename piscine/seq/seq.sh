#!/bin/sh

# Check if the number of arguments is correct
if [ "$#" -ne 3 ]; then
    echo "Usage: ./seq.sh FIRST INCREMENT LAST" >&2
    exit 1
fi

FIRST=$1
INCREMENT=$2
LAST=$3

# Check if INCREMENT is zero
if [ "$INCREMENT" -eq 0 ]; then
    exit 1
fi

# If FIRST == LAST, display FIRST
if [ "$FIRST" -eq "$LAST" ]; then
    echo "$FIRST"
    exit 0
fi

# Generate the sequence
if [ "$FIRST" -lt "$LAST" ]; then
    if [ "$INCREMENT" -le 0 ]; then
        exit 1
    fi
    seq "$FIRST" "$INCREMENT" "$LAST"
elif [ "$FIRST" -gt "$LAST" ]; then
    if [ "$INCREMENT" -ge 0 ]; then
        exit 1
    fi
    seq "$FIRST" "$INCREMENT" "$LAST"
fi

exit 0
