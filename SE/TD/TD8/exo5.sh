while [[ $# -ne 0 ]]; do
    ls $1 >> /dev/null
    if [[ $? -eq 0 ]]; then  #si le code de retour de la commande prdecedente est == 0, alors on passe à la suite
        for n in $(ls $1)
        do
            if [[ -d $1/$n ]]; then #verifie si c'est bien un repretoire
                echo $n
            fi
        done
    else
        echo "Erreur, le dossier existe pas"
    fi
    shift
done
