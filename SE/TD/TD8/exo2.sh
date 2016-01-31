#!/bin/zsh
for n in $(ls $1)
do
    if [ -d $1/$n ]
    then
        echo "$1/$n"
    fi
done
