'''
Description:  Cellofaan
Author:       Bart Volkaerts
Date:         5/12/2013
'''

def paars(films):
  rows = 0                                #---------------------------
  columns = 0                             # Veel code om gewoon het maximum aantal rijen en kolommen te bepalen
  for element in films:
    temp_r = element[0]+element[2]
    if temp_r > rows:
      rows = temp_r
    temp_c = element[1]+element[3]
    if temp_c > columns:
      columns = temp_c                    #---------------------------

  matrix = [['' for x in range(rows)] for x in range(columns)]  # een matrix creeren van r x k

  for element in films:                                   #--------------------------------
    for i in range(element[1],element[1]+element[3]):     # Van linksboven tot rechtsonder de gewenste letter
      for j in range(element[0],element[0]+element[2]):   # 'bij' in de matrix zetten
        matrix[i][j] += element[4]                        #--------------------------------
        
  counter = 0                                         #------------------------------
  for element in matrix:
    for subelement in element:                        # Elk element van de matrix afgaan
      if 'R' in subelement and 'B' in subelement:     # en kijken of er een B AND R in een vakje zitten (=paars)
        counter+=1                                    # Counter optellen

  return counter                                      #------------------------------


def cellofaan(locatie):                               #------------------------------
  f = open(locatie, 'r')
  lijst = []                                          # File opendoen en inlezen en parsen naar het gewenste formaat
  for line in f:
    newl = line[1:]
    newl = newl.strip().split()
    lijst.append((int(newl[0]),int(newl[1]),int(newl[2]),int(newl[3]),str(line[0])))
    print lijst

  return paars(lijst)                                 # Met onze gemaakte lijst gewoon vorige functie oproepen
                                                      #------------------------------


#Functie oproepen
print paars([(0, 0, 5, 5, 'R'), (10, 0, 5, 5, 'R'), (3, 2, 9, 2, 'B')])
print cellofaan('cellofaan.txt')
