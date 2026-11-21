# 8)Write a script to display the multiplication table of a number.

#!/bin/bash

#Prompt user enter a number
echo "Enter a number to generate its multiplication table: "
read num

#Print the multiplication table
echo "Multiplication table for $num: "
for i in {1..10}
    do
        echo "$num * $i = $((num*i))"
done