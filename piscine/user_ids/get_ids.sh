#!/bin/bash

# Extract user IDs from /etc/passwd
# Cut the field between the second and third ':' character,
# sort them in reverse order and remove duplicates
cut -d ':' -f 3 /etc/passwd | sort -rn | uniq
