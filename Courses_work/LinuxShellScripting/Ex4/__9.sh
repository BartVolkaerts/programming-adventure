#!/bin/bash

for filename in /*
do
  if [ -d "$filename" ]
  then
    echo $filename
    ls -l $filename
  fi
done
