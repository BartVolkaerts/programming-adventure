def codontabel(locatie):
  f = open(locatie, 'r')
  dict1 = {}
  for element in f:
    element = element.strip().split()
    for i in range(0,len(element),2):
      if element[i+1] == 'Stop':
        dict1[element[i]] = '*'
      else:
        dict1[element[i]] = element[i+1]

  return dict1

def omgekeerde_codontabel(dict1):
  dict2 = {}
  for element in dict1:
    if dict1[element] not in dict2:
      dict2[dict1[element]] = set()
    dict2[dict1[element]].add(element)

  return dict2

def mRNA(eiwit, codontabel):
  tabel = omgekeerde_codontabel(codontabel)
  eiwit = eiwit + '*'
  temp = 0
  for element in eiwit:
    if temp == 0:
      temp = len(tabel[str(element)])
    else:
      temp *= len(tabel[str(element)])

  return temp
  

tabel = codontabel('standard_code.txt')
omgekeerde_codontabel(tabel)

print mRNA('MA', tabel)

print mRNA('MWQWQWY', tabel)

print mRNA('MRNA', tabel)

