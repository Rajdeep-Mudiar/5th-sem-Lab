# 6)Write a script to check if a number is prime or not.

#!/bin/bash

#Prompt user to enter the number
echo "Enter the number : "
read num

#Check if the number is prime
is_prime=1
for((i=2;i<num/2;i++))
do
    if [ $((num%i)) -eq 0 ];
    then
        is_prime=0
        break
    fi
done

if [ $num -le 1 ];
    then
        echo "$num is not a prime number"
elif [ $is_prime -eq 1 ];
    then
        echo "$num is a prime number"
else
    echo "$num is not a prime number"

fi
