#!/bin/bash

# Create a script to calculate the power of a number

echo "Enter the base:"
read base

echo "Enter the exponent:"
read exponent

result=1

for ((i=1; i<=exponent; i++))
do
    result=$((result * base))
done

echo "$base^$exponent = $result"
