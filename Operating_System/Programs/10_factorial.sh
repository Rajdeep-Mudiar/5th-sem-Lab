#!/bin/bash
# Write a shell script to find the factorial of a number.

echo "Enter a number:"
read n

if (( n < 0 ))
then
    echo "Factorial is not defined for negative numbers."
    exit 1
fi

fact=1

for ((i=1; i<=n; i++))
do
    fact=$((fact * i))
done

echo "Factorial of $n = $fact"
