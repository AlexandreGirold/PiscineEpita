#!/bin/sh

if [ $# -ne "1" ];then
        echo "Sorry, excepcted 1 argument but 0 were passed";
        exit "1"
else 
        echo "letsgooooo">>$1
fi
