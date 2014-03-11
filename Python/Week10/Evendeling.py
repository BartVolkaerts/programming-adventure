'''
Description:  Evendeling
Author:       Bart Volkaerts
Date:         3/12/2013
'''

def groepen(vierkant):
  diction = {}

  for element in range(len(vierkant)):
    for subelement in range(len(vierkant)):
      pos = (element,subelement)
      key = vierkant[pos[0]][pos[1]]
      if key not in diction:
        diction[key] = set()
      diction[key].add(pos)

  return diction

def samenhangend(posities):
  lijst = []
  samen = []
  naast = 0
  for element in posities:
    lijst.append(element)

  samen.append(lijst.pop(0))

  while True:

    for element in samen:
      for blokje in lijst:
        if grenst(element, blokje):
          samen.append(blokje)
          lijst.remove(blokje)
          naast = 1
    
    if naast == 0:
      break
    else:
      if lijst == []:
        return True
      naast = 0

  return False

def grenst(tegel1,tegel2):
  values = ((-1,0),(1,0),(0,-1),(0,1))
  x = tegel2[0]-tegel1[0] 
  y = tegel2[1]-tegel1[1] 
  if (x,y) in values:
    return True
  return False


def evendeling(vierkant):
  groepjes = groepen(vierkant)
  aantal = 0
  for element in groepjes:
    if aantal == 0:
      aantal = len(groepjes[element])
    else:
      if aantal != len(groepjes[element]):
        return False
    if not samenhangend(groepjes[element]):
      return False
  return True

# Functie oproepen
rooster = [[1, 1, 1], [2, 2, 3], [2, 3, 3]]
groepen(rooster)

rooster = [[1, 1, 1, 5, 5], [2, 1, 5, 5, 4], [2, 1, 5, 4, 4], [2, 2, 4, 4, 3], [2, 3, 3, 3, 3]]
groepen(rooster)

samenhangend({(1, 2), (1, 3), (2, 2), (0, 3), (0, 4)})
samenhangend({(1, 2), (1, 4), (2, 2), (0, 3), (0, 4)})

rooster = [[1, 1, 1], [2, 2, 3], [2, 3, 3]]
print evendeling(rooster)

rooster = [[1, 1, 1], [2, 2, 3], [3, 3, 2]]
print evendeling(rooster)

rooster = [[1, 1, 1, 5, 5], [2, 1, 5, 5, 4], [2, 1, 5, 4, 4], [2, 2, 4, 4, 3], [2, 3, 3, 3, 3]]
print evendeling(rooster)
