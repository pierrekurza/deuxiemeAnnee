#!/bin/bash
last > userLast
nbL=$(cut userLast | wc -l)
nbL=$(echo $nbL - 2 | bc)
cat userLast | head -n $nbL > userLast
