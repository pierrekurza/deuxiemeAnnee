#!/bin/bash

listeFichiers=$(ls $1)
if [[ $? -eq 0 ]]; then
    for i in $listeFichiers
    do
        if [[ -f $1/$i ]]; then
                echo $(stat -c %x $1/$i) >> $1/$i
        fi
    done
fi
