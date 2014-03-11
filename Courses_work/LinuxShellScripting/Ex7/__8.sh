#!/bin/bash

function add
{
#  sum=$( expr $1 + $2 )
  let sum=$1+$2
#  return $sum
}

add 1 2
echo $sum
