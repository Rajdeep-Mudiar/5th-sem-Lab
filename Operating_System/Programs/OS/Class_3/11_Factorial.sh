# 11)Write a Shell program to find the factorial of a number.

echo "Enter a Number"
read n

# Handle edge case for 0! and 1!
fact=1
i=$n

while (( i > 1 )); do
    fact=$((fact * i))
    i=$((i - 1))
done

echo "The Factorial of the given Number is $fact"