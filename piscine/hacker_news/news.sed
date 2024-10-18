#!/bin/sed -nf

# Extract titles and URLs from the Hacker News HTML
s/<a href="\(https:\/\/news\.ycombinator\.com\/item\?id=[0-9]*\)" class="storylink">\([^<]*\)<\/a>/\*\*\2\*\*\n\1\n/
