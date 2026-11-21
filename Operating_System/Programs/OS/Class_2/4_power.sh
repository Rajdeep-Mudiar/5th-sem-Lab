# 4)Write a script to calculate the power of a number.
#!/bin/bash
read -p "Enter the number: " num
read -p "Enetr the power: " pow

echo "$((num))to the power $((pow)) = $((num**pow))"

