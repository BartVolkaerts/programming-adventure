#!/bin/bash

colors=(red yellow green blue black orange white)
colors[8]=purple
colors[5]=brown
colors[1]=

echo ${colors[*]}

for shade in 4 1 0
do
  echo ${colors[$shade]}
done
