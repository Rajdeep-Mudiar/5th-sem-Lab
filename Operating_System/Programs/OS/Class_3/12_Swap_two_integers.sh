# 12)Write a Shell program to swap the two integers.

echo -n "Enter two numbers (separated by a space): "
read a b

echo "Before swapping: a = $a, b = $b"

# Swap using a temporary variable
temp=$a
a=$b
b=$temp

echo "After swapping: a = $a, b = $b"