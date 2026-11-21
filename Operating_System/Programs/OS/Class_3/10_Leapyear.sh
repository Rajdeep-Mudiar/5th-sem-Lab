# 10)Write a Shell program to check the given year is leap year or not 

echo "Enter the year"
read y

# Check accurate leap year conditions
if (( (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) )); then
    echo "$y is a leap year"
else
    echo "$y is not a leap year"
fi