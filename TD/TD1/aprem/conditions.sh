#!/bin/sh

# Tu es pauvres ?

if [ $# -ne '1' ];
then 
    echo "Input only one parameter, your money per month"
elif [ ${1} -ge "10000" ];
then 
    echo "You are rich my friend, here's my number"
else
    echo "you are poor, get away from me"

fi

