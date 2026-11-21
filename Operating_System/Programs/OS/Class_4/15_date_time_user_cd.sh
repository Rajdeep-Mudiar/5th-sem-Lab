# 15)Write a script to display the current date,time,username and Working directory.

#!/bin/bash

echo "Current Date : $(date +%d-%m-%y)"
echo "Current Time : $(date +%H:%M:%S)"
echo "Username : $(whoami)"
echo "Working Dir : $(pwd)"