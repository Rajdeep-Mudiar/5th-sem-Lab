# Create a script to display the multiplication table of a number 


#!/bin/bash

echo "Enter a number:"
read n

echo "Multiplication table of $n:"

for ((i=1; i<=10; i++))
do
    echo "$n x $i = $((n * i))"
done