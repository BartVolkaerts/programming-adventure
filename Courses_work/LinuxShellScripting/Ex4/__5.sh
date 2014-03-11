#!/bin/bash

until [ -s /tmp/$LOGNAME ]
do
  sleep 10
done
echo "Got it"
