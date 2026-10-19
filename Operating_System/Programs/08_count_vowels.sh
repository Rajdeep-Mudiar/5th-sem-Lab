# write a shell script to count the vowels,consonants,digits and spaces in a string

#!/bin/bash

echo "Enter a string:"
read str

vowels=0
consonants=0
digits=0
spaces=0

for ((i=0; i<${#str}; i++))
do
    ch="${str:i:1}"

    case "$ch" in
        [aeiouAEIOU])
            ((vowels++))
            ;;
        [a-zA-Z])
            ((consonants++))
            ;;
        [0-9])
            ((digits++))
            ;;
        " ")
            ((spaces++))
            ;;
    esac
done

echo "Vowels = $vowels"
echo "Consonants = $consonants"
echo "Digits = $digits"
echo "Spaces = $spaces"