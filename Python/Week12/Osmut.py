'''
Description:  Osmuthalluthexium
Author:       Bart Volkaerts
Date:         10/12/2013
'''

import random

class NaamGenerator(object):
  def __init__(self):
    self.prefixen = set()
    self.triples = {}

    self.voorbeeldnamen = set()


  def naamToevoegen(self, voorbeeldnaam):
    if not voorbeeldnaam.istitle():
      raise AssertionError("ongeldige naam") 

    self.voorbeeldnamen.add(voorbeeldnaam)

    voorbeeldnaam += '_'
    self.prefixen.add(voorbeeldnaam[0:3])
    voorbeeldnaam = voorbeeldnaam[1:]
    lengte = len(voorbeeldnaam)
    for i in range(0,lengte-2):
      if voorbeeldnaam[i:i+2] not in self.triples:
        self.triples[voorbeeldnaam[i:i+2]] = set()
      self.triples[voorbeeldnaam[i:i+2]].add(voorbeeldnaam[i+2])


  def namenToevoegen(self, tekstbestand):
    for f in open(tekstbestand, 'r'):
      f = f.strip()
      self.naamToevoegen(f)


  def naam(self):
    naam = random.sample(self.prefixen,1)[0]
    while True:
      temp = random.sample(self.triples[naam[-2:]],1)[0]
      if temp == '_':
        if naam in self.voorbeeldnamen:
          naam = random.sample(self.prefixen,1)[0]
          temp = ''
        else:
          break
      else:
        naam += temp
    return naam

#Commando's
chemGen = NaamGenerator()

chemGen.naamToevoegen('Osmium')

chemGen.naamToevoegen('Bismut')

chemGen.namenToevoegen('shortlist_elementen.txt')
chemGen.prefixen
chemGen.triples

chemGen.naam()
chemGen.naam()
chemGen.naam()
chemGen.naam()


