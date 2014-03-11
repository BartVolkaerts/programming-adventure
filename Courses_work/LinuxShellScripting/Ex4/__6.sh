#!/bin/bash

while [ $# -gt 0 ]
do
  echo $1
  sleep 2
  shift
done >> /tmp/$LOGNAME
