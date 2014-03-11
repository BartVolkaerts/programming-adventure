#!/bin/bash

while true
do
  for i in 0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1
  do
    echo 0123456789876543210 | grep ${i} --color=auto
    sleep 0.04
  done
done
