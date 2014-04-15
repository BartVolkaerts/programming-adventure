#!/usr/bin/python
# Author: Bart Volkaerts

import os,sys
import subprocess

f = open('MODTREE')
mods = {}
mods_enabled = {}
mods_pos = {}
valid_setup = 0
invalid_setup = 0
commands = []

def check_dep():
  for key in mods_enabled.keys():
    if mods_enabled[key] == 1:
      for element in mods[key]:
        if element != '' and mods_enabled[element] != 1:
          return 1
  return 0

i = 0
while(True):
  r = f.readline()
  if r == '':
    break
  if r != '\n':
    strings = r.split(':')
    mod = strings[0]
    deps = (strings[1])[1:].rstrip('\n').split(' ')
    mods[mod] = deps
    mods_pos[i] = mod
    i += 1

poss = 2**len(mods)
for j in range(1,poss):
  bin_mask = '{0:0' + str(len(mods)) + 'b}'
  bin_number = bin_mask.format(j)
  for i in range(len(mods)):
    if int(bin_number[i]) == 1:
      mods_enabled[mods_pos[i]] = 1
    else:
      mods_enabled[mods_pos[i]] = 0
  if check_dep() == 0:
    valid_setup += 1
    command = 'make dummy '
    for key in mods_enabled.keys():
      if mods_enabled[key] == 1:
        command += key + "=1 "
      else:
        command += key + "=0 "
    commands.append(command)
  else:
    invalid_setup += 1

print "Total possible setups: ", (valid_setup + invalid_setup)
print "Valid: ", valid_setup
print "Invalid: ", invalid_setup

time_to_calc_days = valid_setup * 5 / 3600 / 24
print "\nApproximate time to check all valid setups: "
print "%0.1f days"%time_to_calc_days

#nul = open('/dev/null', 'w')
#for i in commands:
#  print 'Checking config:\n\t%s' % i
#  os.system('make clean >/dev/null')
#  args = i.split(' ')
#  subprocess.call(['make','clean'], shell=True, stdout=nul, stderr=nul)
#  subprocess.call(args[-1], shell=True,stdout=nul, stderr=nul)==0 or sys.exit(1)
#  print "CONFIG OK!"
#  print

sys.exit(0)
