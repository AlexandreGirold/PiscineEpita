#!/bin/sh

if [ "$#" -eq 0 ]
then
    exit 1
fi

if [ "$#" -gt 1 ]
then
    exit 1
fi

num=$1
fact=1

while [ $num -gt 1 ]
do
  fact=$((fact * num))  #fact = fact * num
  num=$((num - 1))      #num = num - 1
done

echo "$fact"
exit 0;
