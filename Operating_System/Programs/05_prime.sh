# Create a script to check if a number is prime or not 

#!/bin/bash

echo "Enter a number:"
read n

if [ "$n" -lt 2 ]
then
    echo "$n is not a prime number."
    exit
fi

flag=0

for ((i=2; i*i<=n; i++))
do
    if [ $((n % i)) -eq 0 ]
    then
        flag=1
        break
    fi
done

if [ "$flag" -eq 0 ]
then
    echo "$n is a prime number."
else
    echo "$n is not a prime number."
fi