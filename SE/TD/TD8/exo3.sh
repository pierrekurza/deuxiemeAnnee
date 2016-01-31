ls $1 >> /dev/null
if [ $? -eq 0 ]
then
    for n in $(ls $1)
    do
        if [ -d $1/$n ]
        then
            echo "$1/$n"
        fi
done
else
    echo "Nada !"
fi
