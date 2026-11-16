#!/bin/bash

# Write a shell script to swap two integers using a temporary variable

echo "Enter two integers:"
read a b

echo "Before swapping: a = $a, b = $b"

temp=$a
a=$b
b=$temp

echo "After swapping:  a = $a, b = $b"
