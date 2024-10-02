#!/bin/sh

touch \ 

touch \\

touch -- --

touch \|

touch \"

touch \'

touch -- \--"\$i*'\"\\"

touch "# Exams are fun!"

touch ";\`kill -9 0\`"

for i in $(seq 50); do 
        mkdir "$i"
        cd "$i"
done

touch farfaraway


