'''
Description:  Open Reading Frames
Author:       Bart Volkaerts
Date:         14/11/2013
'''

def ORFs(string, start_tup, stop_tup):
  lijst = []
  lengte = len(string)
  start_or_stop = 0
  for i in range(3):
    start = i
    start_or_stop=0
    while True:
      tmp_str = string[start:start+3]
      if start_or_stop == 0:
        if tmp_str in start_tup:
          start_tmp = start
          start_or_stop = 1
      elif start_or_stop == 1:
        if tmp_str in stop_tup:
          start_or_stop = 0
          lijst.append((start_tmp,start+2,i+1))

      start += 3
      if start > len(string)-3:
        break;

  lijst = sorted(lijst, key=lambda x: x[0])
  print lijst


# Functie oproepen
ORFs('gcccttaattttattcattggattccattcattaacgtgctgatgtcccatttgttta', ['att', 'gca', 'gcc'], ['tct', 'tga', 'ttt'])
ORFs('cgtgtgcacaactcaccccgtagacccaaaatgtggataacatg', ['aca', 'gtg'], ['aaa', 'ccc', 'gac'])
ORFs('cgagggctctcactgggacggcagaggctagtcacagtat', ['agt'], ['gac', 'ggc'])
