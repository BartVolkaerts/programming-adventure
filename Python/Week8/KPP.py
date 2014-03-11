'''
Description:  Koninginnen, paarden en pionnen
Author:       Bart Volkaerts
Date:         14/11/2013
'''

def veiligeVierkanten(r,k,input_list):
  matrix = [[0 for x in range(k)] for x in range(r)]  # een matrix creeren van r x k
  print matrix

  for element in input_list:
    matrix[element[1]][element[2]] = element[0]       # vul het bord met de schaakstukken op de juiste positie

  for x in range(r):
    for y in range(k):
      if matrix[x][y] == 'K':
        berekenPaardPos(matrix, x, y, r,k)
      elif matrix[x][y] == 'Q':
        berekenQueenPos(matrix, x, y, r,k)

  aantalVrije = 0
  for x in range(r):
    for y in range(k):
      if matrix[x][y] == 0:
        aantalVrije += 1

  print aantalVrije

def berekenPaardPos(matrix, r, k, rr,kk):
  jumps = ((-2,1),(-2,-1),(-1,2),(-1,-2),(1,2),(1,-2),(2,1),(2,-1))
  for element in jumps:
    x = r+element[0]
    y = k+element[1]
    if (x>=0 and x<rr and y>=0 and y<kk):
      if matrix[x][y] == 0 or matrix[x][y] == 'k' or matrix[x][y]=='q':
        matrix[x][y] = 'k'

def berekenQueenPos(matrix, r, k, rr, kk):
  moves = ((-1,0),(1,0),(0,-1),(0,1),(-1,-1),(-1,1),(1,1),(1,-1))
  for element in moves:
    x = r
    y = k
    while True:
      x = x+element[0]
      y = y+element[1]
      if (x>=0 and x<rr and y>=0 and y<kk and (matrix[x][y] == 0 or matrix[x][y] == 'k' or matrix[x][y]=='q')):
        matrix[x][y] = 'q'
      else:
        break;

# Functie oproepen
veiligeVierkanten(4, 4, (('K', 0, 1), ('Q', 0, 3), ('P', 1, 2), ('Q', 1, 3)))
veiligeVierkanten(2, 3, (('Q', 0, 1), ('K', 0, 0)))
veiligeVierkanten(8, 8, (('K', 4, 3), ('K', 7, 7)))
veiligeVierkanten(8, 8, (('Q', 4, 3), ))
