#!/bin/sh

for var in "$@"; do
	if [ -f "$var" ]; then 
		echo "$var": file
	elif [ -d "$var" ]; then 
		echo "$var": directory
	else
		echo "$var": unknown
	fi

done

		

