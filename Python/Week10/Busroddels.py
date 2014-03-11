'''
Description:  Busroddels
Author:       Bart Volkaerts
Date:         27/11/2013
'''
import collections

def busroddels(routes):
  aantal = len(routes)                #----------------------------------------------------------
  lijst = []                          #
  for i in range(aantal):             # Omzetten van de tuple van tuples naar een lijst met deques
    lijst.append(collections.deque()) # 
    lijst[i].extend(routes[i])        #----------------------------------------------------------

  matrix = [[0 for x in range(aantal)] for x in range(aantal)]  #---------------------------------------------------------- 
  for i in range(aantal):                                       # Vierkant maken en diagonaal zetten
    matrix[i][i] = 1                                            #----------------------------------------------------------

  for i in range(1440):                                         #----------------------------------------------------------
    t = tuple(x[0] for x in lijst)                          # -> elke eerste waarde van elk deque nemen en in een tuple plaatsen
    lijst2 = searchformatches(t)                            # -> zoeken naar matches in de tuple en terug geven (zelf gedef. functie)
    for element in lijst2:                                  # -> voor elk gevonden match
      for j in range(aantal):
        temp = matrix[element[0]][j] or matrix[element[1]][j] #
        matrix[element[0]][j] = temp                          # kruisjes van elke driver OF'en
        matrix[element[1]][j] = temp                          #

    for element in lijst:                                   # -> elk deque 1 plaats opschuiven
      element.rotate(-1)                                        #----------------------------------------------------------

    if checkmatrix(matrix):
      return i

  return -1

def checkmatrix(matrix):        #----------------------------------------------------------
  for element in matrix:        # Deze functie kijkt gewoon of er nog ergens een 0 zit in de matrix
    if 0 in element:            # Dwz dat er een chauffeur een roddel nog niet kent.
      return False              #
  return True                   #----------------------------------------------------------

def searchformatches(stops):    #----------------------------------------------------------
  lijst = []                      # -> lege lijst maken
  aantal = len(stops)             # -> hoeveel chauffeurs staan er stil = aantal
  for i in range(aantal-1):         #
    for j in range(i+1,aantal):     # Beginnen bij 1 en naar achter gaan en zoeken naar matches
      if stops[i] == stops[j]:      # 
        lijst.append((i,j))         # Toevoegen aan lijst
  return lijst                  #----------------------------------------------------------

# Functie oproepen
print busroddels(((1, 2, 3, 4, 5), (5, 6, 7, 8), (3, 9, 6)))
print busroddels(((1, 2, 3), (2, 1, 3), (2, 4, 5, 3)))
print busroddels(((1, 2), (2, 1)))
print busroddels(((5, 1, 9, 5, 0, 3, 6, 6), (5, 4, 9, 5, 6, 4, 1, 3), (1, 4, 0, 7), (1, 3, 3, 2), (3, 6, 6, 2, 0, 7)))
