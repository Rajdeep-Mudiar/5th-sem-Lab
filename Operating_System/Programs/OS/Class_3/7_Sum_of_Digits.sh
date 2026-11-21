# 7)Write a script to find the sum of digits of a number.

#!/bin/bash

#Prompt user to enter a number
echo "Enter a number: "
read num

#Initialize Sum
sum=0

#Calculate the sum of Digits
while [ $num -gt 0 ]
    do
        digit=$((num%10))
        sum=$((sum+digit))
        num=$((num/10))
    done

#Output the result
echo "Sum of Digits: $sum"