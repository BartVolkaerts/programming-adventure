'''
Description:  Oersoep
Author:       Bart Volkaerts
Date:         5/12/2013
'''

# Kijken of elk element van de molecule voorkomt in de oersoep dictionary
# EN dat het aantal atomen evenveel of meer zijn in oeroep dan in de molecule
def abiogenese(moleculen,oersoep):
  for element in moleculen:
    if element in oersoep:
      if moleculen[element] > oersoep[element]:
        return False
    else:
      return False

  return True


def leesMoleculen(locatie):
  f = open(locatie, 'r')
  dict1 = {}
  for line in f:
    dict2 = {}
    line = line.strip().split()
    key = line[0]
    line = line[1:]
    for i in range(0,len(line),2):
      dict2[line[i]] = int(line[i+1])
    dict1[key] = dict2

  return dict1

# Kijken welke moleculen uit moleculen dictionary gemaakt kunnen worden met atomen in oersoep
# Elke moleculen wordt apart bekeken
# We maken gebruik van de functie abiogenese
def experiment1(moleculen,oersoep):
  lijst = []
  for element in moleculen:
    if abiogenese(moleculen[element],oersoep):
      lijst.append(element)
  return sorted(lijst)


# Kijken welke moleculen uit moleculen dictionary gemaakt kunnen worden met atomen in oersoep
# Moleculen worden niet apart bekeken, we checken of we elk element kunnen maken met de atomen in oersoep
# (dus oersoep verminder na elke check in aantal)
# We maken gebruik van de functie abiogenese
def experiment2(moleculen,oersoep):
  for element in moleculen:
    if abiogenese(moleculen[element],oersoep):
      for element2 in moleculen[element]:
        if element2 in oersoep and oersoep[element2] >= (moleculen[element])[element2]:
          oersoep[element2] -= (moleculen[element])[element2]
        else:
          return False
    else:
      return False
  return True


#Functie oproepen
oersoep = {'N':2, 'Na':2, 'O':5, 'H':4}
print abiogenese({'Si': 1, 'O': 2}, oersoep)
print abiogenese({'H': 3, 'N': 1}, oersoep)

moleculen = leesMoleculen('moleculen.txt')
print moleculen['zand']
print moleculen['ammoniak']

print experiment1(moleculen, oersoep)

moleculen1 = {'ammoniak': {'H': 3, 'N': 1}, 'natronloog': {'Na': 1, 'O': 1, 'H': 1}}
print experiment2(moleculen1, oersoep)
moleculen2 = {'zand': {'Si': 1, 'O': 2}, 'ammoniak': {'H': 3, 'N': 1}}
print experiment2(moleculen2, oersoep)
