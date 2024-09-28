#!/bin/sh

[ "$#" -ne 1 ] && echo 'Sorry, expected 1 argument but 0 were passed' && exit "1"|| {
[ -x "$1" ] &&  echo "YOLO">>$1 # if the argument is executable then execute it
}
