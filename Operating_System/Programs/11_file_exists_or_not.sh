# write a shell script to check whether a given file exists or not

#!/bin/bash

echo "Enter the filename:"
read filename

if [ -e "$filename" ]
then
    echo "File exists."
else
    echo "File does not exist."
fi