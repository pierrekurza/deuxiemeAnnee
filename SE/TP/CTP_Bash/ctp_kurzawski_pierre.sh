#!/bin/bash
IFS='/'
set $1
leChemin=(cd $1)
for (( i in leChemin )); do
  if [[ leChemin -eq false ]]; then
    echo "Chemin non valide"
  else
    echo $($i/$1)
    echo "Chemin valide"
  fi
done
