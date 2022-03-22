#!/bin/bash
dir=$1
mkdir $dir
for (( i=1; i <= $RANDOM % 8 + 3; i++ ))
do
    touch "$dir/$i.txt"
    echo "test_message">"$dir/$i.txt"
    mkdir $dir/$i
    for (( j=1; j <= $RANDOM % 8 + 3; j++ ))
    do  
        touch "$dir/$i/$j.txt"
        echo "test_message">"$dir/$i/$j.txt"
        mkdir $dir/$i/$j
        for (( k=1; k <= $RANDOM % 8 + 3; k++ ))
        do  
            touch "$dir/$i/$j/$k.txt"
            echo "test_message">"$dir/$i/$j/$k.txt"
        done
    done
done