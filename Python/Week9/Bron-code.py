'''
Description:  Bron-code
Author:       Bart Volkaerts
Date:         26/11/2013
'''

def positie(p1, p2):
  a=p1[0]
  b=p1[1]
  x=p2[0]
  y=p2[1]
  value = a*y-b*x
  if value>0:
    return 1;
  elif value<0:
    return -1
  else:
    return 0

def broncode(a,b,c,alternatief=False):
  text = ''
  coor = [0,0]
  waterA = 0
  waterB = 0
  check = -1
  pos = (a,b)

  if alternatief:
    temp = a
    a = b
    b = temp
    check = 1

  while True:
    if alternatief:
      coor[0] += 1
    else:
      coor[1] += 1
    if positie(pos,(coor[0],coor[1])) == check:
      waterA += waterB
      waterB = waterA-a
      text += 'Vul de ' + str(a).strip() + '-liter kruik op met water uit de ' + str(b).strip()+ '-liter kruik.\n'
      if waterB != c:
        waterA = 0
        text += 'Giet de ' + str(a).strip() + '-liter kruik leeg.\n'
      else:
        text += 'De ' + str(b).strip() + '-liter kruik bevat nu ' + str(c).strip() + ' liter.'
        break
      continue
    else:
      if alternatief:
        coor[0] -= 1
      else:
        coor[1] -= 1


    if alternatief:
      coor[1] += 1
    else:
      coor[0] += 1
    if positie(pos,(coor[0],coor[1])) == check:
      if waterB > 0:
        waterA += waterB
        waterB = 0
        text += 'Giet de inhoud van de ' + str(b).strip() + '-liter kruik in de ' + str(a).strip() + '-liter kruik.\n'
      if waterA != c:
        waterB = b
        text += 'Vul de ' + str(b).strip() + '-liter kruik aan de bron.\n'
      else:
        text += 'De ' + str(a).strip() + '-liter kruik bevat nu ' + str(c).strip() + ' liter.'
        break


  print text


# Functie oproepen
positie((3,7),(3,0))
positie((3,7),(0,3))
positie((3,7),(6,14))

broncode(7,3,5)
#broncode(7,3,5,alternatief=True)
