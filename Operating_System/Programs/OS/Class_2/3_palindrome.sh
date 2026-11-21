# 3)Write a script to check if a string is a palindrome.

#!/bin/bash

read -p "Enter the string :" str
rev=$(echo "$str" | rev)

if [ "$str"="$rev" ]
then
	echo "Palindrome"
else
	echo "Not Palindrome"

fi

