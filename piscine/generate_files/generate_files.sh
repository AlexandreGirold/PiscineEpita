#!/bin/sh

FILENAME=default
NUMBER=1
EXTENSION=txt



while [ $# -ne 0 ]; do
        case "$1" in
                "-f" | "--filename") 
                     
		     shift
			FILENAME="$1"
			shift

                        ;;
                "-n" | "--number")
			shift
                     NUMBER="$1"
		     shift
                    ;; 
                
                "-e" | "--extension")
			shift
                     EXTENSION="$1"
		     shift
                    ;;
                *)
                    exit 1
                    ;;

                                
        esac

done
for j in $(seq "$NUMBER"); do
        touch -- "$FILENAME"-"$j"."$EXTENSION"
done        

        
