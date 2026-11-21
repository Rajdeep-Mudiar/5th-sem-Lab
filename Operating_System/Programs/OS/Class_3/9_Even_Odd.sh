# 9)Write a Shell program to check the given number is Even or Odd 

echo "Enter the Number"
read n
r=$((n % 2))

if [ $r -eq 0 ]; then
    echo "$n is Even number"
else
    echo "$n is Odd number"
fi