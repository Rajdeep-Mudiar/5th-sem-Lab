# write a shell script to find the largest and smallest element in an array


#!/bin/bash

echo "Enter the number of elements:"
read n

echo "Enter the array elements:"
for ((i=0; i<n; i++))
do
    read arr[i]
done

largest=${arr[0]}
smallest=${arr[0]}

for ((i=1; i<n; i++))
do
    if (( arr[i] > largest ))
    then
        largest=${arr[i]}
    fi

    if (( arr[i] < smallest ))
    then
        smallest=${arr[i]}
    fi
done

echo "Largest element = $largest"
echo "Smallest element = $smallest"