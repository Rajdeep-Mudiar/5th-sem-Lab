# Write a script to find the second-largest number in a list 

#!/bin/bash

echo "Enter the numbers separated by spaces:"
read -a arr

largest=${arr[0]}
second=${arr[0]}

for num in "${arr[@]}"
do
    if [ "$num" -gt "$largest" ]
    then
        second=$largest
        largest=$num
    elif [ "$num" -gt "$second" ] && [ "$num" -ne "$largest" ]
    then
        second=$num
    fi
done

echo "Largest number: $largest"
echo "Second-largest number: $second"