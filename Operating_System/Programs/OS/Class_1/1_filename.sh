# 1)Write the script to print your name ,age and also add to numbers.

#!/bin/bash

echo "Hello"
echo "Welcome"
name="Bishal Ray"
age=20
echo "Name: $name"
echo "Age: $age"
echo "Enter your name: "
read name
echo "Hello $name"
read -p "Enter your name: " name
echo "Hello $name"
read -p "Enter first no: " a
read -p "Enter second no: " b
echo "Addition=$((a+b))"