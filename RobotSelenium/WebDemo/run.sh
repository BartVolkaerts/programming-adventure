#!/bin/bash
# run this script to start testing with robotframework
# Author: Bart Volkaerts
# Date:   28/02/2014  
#

PWD=`pwd`
OUTDIR="output"

export PYTHONPATH="$PWD/resources/"

if [ -d $OUTDIR ]; then
  rm -rf $OUTDIR/*
fi

python demoapp/server.py&
server_pid=$!
echo $@
pybot --outputdir $OUTDIR $@
kill -9 $server_pid
