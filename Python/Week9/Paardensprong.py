'''
Description:  Paardensprong
Author:       Bart Volkaerts
Date:         26/11/2013
'''

rows = columns = 8

def paard(r, k):                                                    #----------------------------------------------
  lijst = []                                                      
  jumps = ((-2,1),(-2,-1),(-1,2),(-1,-2),(1,2),(1,-2),(2,1),(2,-1))
  for element in jumps:
    x = r+element[0]                                                  # Bekijken naar welke posities het paard kan
    y = k+element[1]                                                  # bewegen vanaf zijn huidige plaats.
    if (x>=0 and x<rows and y>=0 and y<columns):
        lijst.append((x,y))
  lijst = sorted(lijst, key=lambda x: (x[0], x[1]))                   # Lijst sorteren volgens rij, vervolgens volgens kolom.
  return lijst                                                      #----------------------------------------------

def toren(r, k):                                                    #----------------------------------------------
  lijst = []
  moves = ((-1,0),(1,0),(0,-1),(0,1))
  for element in moves:                                              
    x = r
    y = k
    while True:
      x = x+element[0]
      y = y+element[1]
      if (x>=0 and x<rows and y>=0 and y<columns):
        lijst.append((x,y))
      else:
        break
  lijst = sorted(lijst, key=lambda x: (x[0], x[1]))
  return lijst                                                      #----------------------------------------------

def koningin(r, k):                                                 #---------------------------------------------- 
  lijst = []
  moves = ((-1,0),(1,0),(0,-1),(0,1),(-1,-1),(-1,1),(1,1),(1,-1))
  for element in moves:
    x = r
    y = k
    while True:
      x = x+element[0]
      y = y+element[1]
      if (x>=0 and x<rows and y>=0 and y<columns):
        lijst.append((x,y))
      else:
        break
  lijst = sorted(lijst, key=lambda x: (x[0], x[1]))
  return lijst                                                      #----------------------------------------------

def ronde(schaakbord,schaakstuk=paard,gesloten=False):              #----------------------------------------------
  for i in range(1,64):
    current_pos = getPosition(schaakbord,i)
    next_pos = getPosition(schaakbord,i+1)
    if next_pos not in schaakstuk(current_pos[0], current_pos[1]):
      return False
  if gesloten == True:
    current_pos = getPosition(schaakbord,64)
    next_pos = getPosition(schaakbord,1)
    if next_pos not in schaakstuk(current_pos[0], current_pos[1]):
      return False
  return True                                                       #----------------------------------------------

def getPosition(schaakbord, value):                               #----------------------------------------------
  for element in schaakbord:
    for subelement in element:                                      # Kijken op welke x,y positie het gezochte getal zit
      if subelement == value:
        x=schaakbord.index(element)
        y=element.index(subelement)
        return (x,y)                                              #----------------------------------------------




# Functie oproepen
print paard(4, 4)
print paard(0, 3)
print toren(4, 4)
print koningin(2, 3)

schaakbord = [
           [ 3, 22, 49, 56,  5, 20, 47, 58], 
           [50, 55,  4, 21, 48, 57,  6, 19], 
           [23,  2, 53, 44, 25,  8, 59, 46], 
           [54, 51, 24,  1, 60, 45, 18,  7], 
           [15, 36, 43, 52, 17, 26,  9, 62], 
           [42, 39, 16, 33, 12, 61, 30, 27], 
           [35, 14, 37, 40, 29, 32, 63, 10], 
           [38, 41, 34, 13, 64, 11, 28, 31]
        ]
print ronde(schaakbord)
print ronde(schaakbord, schaakstuk=paard, gesloten=True)
print ronde(schaakbord, schaakstuk=toren)
print ronde(schaakbord, schaakstuk=koningin)

schaakbord = [
           [ 1,  2,  3,  4,  5,  6,  7,  8], 
           [28, 29, 30, 31, 32, 33, 34,  9],
           [27, 48, 49, 50, 51, 52, 35, 10],
           [26, 47, 60, 61, 62, 53, 36, 11],
           [25, 46, 59, 64, 63, 54, 37, 12],
           [24, 45, 58, 57, 56, 55, 38, 13],
           [23, 44, 43, 42, 41, 40, 39, 14],
           [22, 21, 20, 19, 18, 17, 16, 15]
        ]
print ronde(schaakbord, schaakstuk=toren)
print ronde(schaakbord, schaakstuk=koningin)
print ronde(schaakbord, schaakstuk=koningin, gesloten=True)
