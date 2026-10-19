# Create a script to find the sum of digits of a number

#!/bin/bash

echo "Enter a number:"
read n

sum=0

while [ "$n" -gt 0 ]
do
    digit=$((n % 10))
    sum=$((sum + digit))
    n=$((n / 10))
done

echo "Sum of digits = $sum"