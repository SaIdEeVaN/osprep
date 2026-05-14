#!/bin/bash

echo "ENTER A NUMBER:"
read a

temp=$a
rev=0

while [ $temp -gt 0 ]
do
	last=$((temp%10))
	rev=$((rev*10+last))
	temp=$((temp/10))
done

echo "THE REVERSE OF THE NUMBER IS : $rev"
