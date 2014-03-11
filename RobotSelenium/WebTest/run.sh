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

echo $@
pybot --outputdir $OUTDIR $@
