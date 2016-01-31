#!/bin/sh
OLDIFS="$IFS"
IFS=':'
tmp=0
for n in $(cat nombre.res)
do
    if [ $n -eq $1 ]
    then tmp=$(expr $tmp + 1)
    fi
done
echo "Il y a $tmp fois le nombre $1"
IFS="$OLDIFS"
