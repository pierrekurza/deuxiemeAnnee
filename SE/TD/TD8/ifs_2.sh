#!/bin/sh
OLDIFS="$IFS"
IFS=':'
val=$(cut -d ":" -f1 nombre.res)
sum=0
for n in $(cat nombre.res)
do
    sum=$(expr $sum + $n)
done
echo "La somme est de : $sum"
IFS="$OLDIFS"
