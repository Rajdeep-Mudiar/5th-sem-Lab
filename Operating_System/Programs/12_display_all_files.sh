# write a shell script to display all the files in the current directory along with their permission

#!/bin/bash

echo "Files and their permissions:"

for file in *
do
    if [ -f "$file" ]
    then
        ls -l "$file"
    fi
done