# 2)Write a script to print Fibonacci series up to n terms.

#!/bin/bash

echo "Fibonacci Series"
a=0
b=1
echo "Enter the number of terms :"
read n 
for((i=0;i<n;i++))
do
	echo -n "$a "
	c=$((a+b))
	a=$b
	b=$c
done

