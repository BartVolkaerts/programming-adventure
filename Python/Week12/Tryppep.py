'''
Description:  Tryptische peptiden
Author:       Bart Volkaerts
Date:         10/12/2013
'''

class eiwitDB(object):
  def __init__(self):
    self.peptiden = {}


  def peptideToevoegen(self, label, tryppep):
    if len(tryppep) < 5 or len(tryppep) > 50 or tryppep[-1] not in ['K','R'] or any(x in ['K','R'] for x in tryppep[0:-1]):
      raise AssertionError("ongeldige peptide")

    if tryppep not in self.peptiden:
      self.peptiden[tryppep] = set()
    self.peptiden[tryppep].add(label)


  def eiwitToevoegen(self, label, sequentie):
    temp = ''
    for char in sequentie:
      temp += char
      if char == 'R' or char == 'K':
        if len(temp) >= 5 and len(temp) <= 50 and temp[-1] in ['K','R'] and any(x not in ['K','R'] for x in temp[0:-1]):
          self.peptideToevoegen(label,temp)
        temp = ''

  
  def eiwittenToevoegen(self, tekstbestand):
    for f in open(tekstbestand, 'r'):
      f = f.strip().split()
      self.eiwitToevoegen(f[0],f[1])


  def identificeer(self, collectie):
    lijst = []
    set1 = set()
    for element in collectie:
      if element in self.peptiden:
        set2 = self.peptiden[element]
      else:
        set2 = set()
      if set1 == set():
        set1 = set2
      else:
        set1 = set1.intersection(set2)

    for element in set1:
      lijst.append(element)
    return sorted(lijst)

#Commando's
unipept = eiwitDB()

unipept.peptideToevoegen('PROT0001', 'ECESAWK')
unipept.peptiden

#unipept.peptideToevoegen('PROT0002', 'WHK')
#unipept.peptideToevoegen('PROT0002', 'ESHLSTLAVQENEIG')
#unipept.peptideToevoegen('PROT0002', 'NWAQNAKIGGADWDCVCR')

unipept.eiwitToevoegen('PROT0002', 'HAEWTDNQCCPVLKECESAWKYEMWQHPGEQHKRRRYEMWQHPGEQHKPCHSHTKVWKRY')
unipept.peptiden

unipept.eiwitToevoegen('PROT0003', 'NRRPCHSHTKECESAWKNRPCHSHTKKPCHSHTKKNRKVWKIPPFFW')
unipept.peptiden

unipept.eiwitToevoegen('PROT0004', 'YEMWQHPGEQHKECESAWKVPYCGFITRPCHSHTKECESAWK')
print unipept.peptiden
"""
print unipept.identificeer(['VPYCGFITR'])
print unipept.identificeer({'ECESAWK', 'PCHSHTK'})
print unipept.identificeer(('YEMWQHPGEQHK', 'ECESAWK', 'PCHSHTK'))
print unipept.identificeer({'PCHSHTK', 'VPYCGFITR'})

unipept.eiwittenToevoegen('eiwitten.txt')
unipept.peptiden
print unipept.identificeer(('YEMWQHPGEQHK', 'VPYCGFITR', 'ECESAWK'))
print unipept.identificeer(('PCHSHTK', 'AYDDEVASFPGCMMATK'))
print unipept.identificeer(['NEGNLNVMK'])
"""
