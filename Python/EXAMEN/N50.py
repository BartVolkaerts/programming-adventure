def N50_dalend(lijst, grootte=None):
  lijst = sorted(lijst)
  if not grootte:
    grootte = sum(lijst)
  
  temp=0
  for element in reversed(lijst):
    temp += element
    if temp >= grootte/2:
      return element

def N50_stijgend(lijst, grootte=None):
  lijst = sorted(lijst)
  if not grootte:
    grootte = sum(lijst)
  
  temp=0
  for element in lijst:
    temp += element
    if temp >= grootte/2:
      return element

def N50(lijst, grootte=None):
  dalend = N50_dalend(lijst, grootte)
  stijgend = N50_stijgend(lijst, grootte)
  getal = (stijgend+dalend)/2
  return float(getal)




contigs = (2, 2, 2, 3, 3, 4, 8, 8)
print N50_dalend(contigs)

print N50_stijgend(contigs)

print N50(contigs)

contigs = (5, 8, 6, 4, 6, 1, 1)
print N50_dalend(contigs, grootte=40)

print N50_stijgend(contigs, grootte=40)

print N50(contigs, 40)

