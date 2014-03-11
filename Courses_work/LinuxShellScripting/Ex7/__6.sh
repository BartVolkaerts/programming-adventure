#!/bin/bash

sum=$( expr 10 + 3 / \( 4 - 2 \))
echo $sum
string=$( s=-1; while (( (s+=1) <= 9 )); do echo "$s"; done)
echo $string
