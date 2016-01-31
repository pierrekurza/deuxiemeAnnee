#!/bin/zsh
OLDIFS="$IFS"
IFS=$':'

val=$(cut -d ":" -f1 nombre.res)
for n in $(cat nombre.res)
do
    if [ $n -lt $val ]
    then
        val=$n
    fi
done

echo "La valeur minimale est : $val"
IFS="$OLDIFS"
