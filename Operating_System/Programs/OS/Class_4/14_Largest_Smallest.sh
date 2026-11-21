# 14)Write a script to find the largest and smallest element in an array.

#!/bin/bash

echo "Enter the number of elements : "
read n
echo "Enter the elements : "
for ((i=0;i<n;i++))
    do 
        read arr[$i]
    done
        largest=${arr[0]}
        smallest=${arr[0]}

for ((i=1;i<n;i++))
    do 
        if [ ${arr[$i]} -gt $largest ]
            then
                largest=${arr[$i]}
        fi

        if [ ${arr[$i]} -lt $smallest ]
            then
                smallest=${arr[$i]}
        fi

done

echo "Largest Element = $largest"
echo "Smallest Element = $smallest"

