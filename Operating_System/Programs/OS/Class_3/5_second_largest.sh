# 5)Write a script to find the second-largest number in a list.

#!/bin/bash
#Prompt user to enter numbers
echo "Enter a list of numbers seperated by Spaces : "
read -a numbers

#Sort the array and find the second largest
sorted=($(echo "${numbers[@]}"| tr ' ' '\n' | sort -nr))

#Output the second largest number
echo "The Second largest number is: ${sorted[1]}"

# Handling Duplicate Numbers
# echo "Enter a list of numbers seperated by Spaces : "
# read -a numbers
# sorted= ($(echo "${numbers[@]}" | tr ' ' '\n' | sort -unr))
# echo "The Second largest number is: ${sorted[1]}"