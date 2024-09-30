#!/bin/sh
# ne marche pas v1
for arg; do
    for file in ?.*; do
        #echo $file = "$arg.*"
        case $file in
               !$arg.*) 
                      cp $file trash/
                 ;;
                 *)
                      echo nooooooooo
        esac
    done
done

# v2 
#for j in *.[!"$*"]; do
#    cp $j "trash"
#done
