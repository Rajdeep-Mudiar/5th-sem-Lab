# write a shell script to display the current date,time,username and working directory

#!/bin/bash

echo "Current Date:"
date +%d-%m-%Y

echo "Current Time:"
date +%H:%M:%S

echo "Username:"
whoami

echo "Working Directory:"
pwd