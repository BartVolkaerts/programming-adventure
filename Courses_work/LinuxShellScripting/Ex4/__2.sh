#!/bin/bash

if [ $# -lt 3 ]
then
  echo "Minder dan 3 argumenten"
  exit 1
else
  echo $0
  exit 0
fi
