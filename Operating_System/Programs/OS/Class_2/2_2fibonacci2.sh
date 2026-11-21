#!/bin/bash

echo "Fibonacci Series"
a=0
b=1

read -p "Enter the number of terms: " n
for((i=0;i<n;i++))
do
	echo -n "$a "
	c=$((a+b))
	a=$b
	b=$c
done

