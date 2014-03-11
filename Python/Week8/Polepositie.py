'''
Description:  Polepositie
Author:       Bart Volkaerts
Date:         6/11/2013
'''

def startposities(input_tuples):
  output = [None]*len(input_tuples)   # Een lijst creeren met een fixed size. Handig voor indexatie.
  i = 0
  for element in input_tuples:        # Voor elke tuple van de invoer
    place = i+element[1]              # Oorspronkelijke plaats berekenen
    if place < len(input_tuples) and place >= 0:  # Kijken of het bord geen fouten geeft (anders index buiten range = ERROR)
      output[place] = element[0]      # Het cijfer van de wagen zetten op de berekende oorspronkelijke plaats
      i = i + 1                       # Naar de volgende
    else:
      return []                       # Als plaats niet in de range zit (fout op het bord) een lege lijst returnen
  if None in output:                  # Als er nog een 'None' in de lijst zit, staat er waarschijnlijk ook een fout op het bord. 
    return []                         # en dus lege lijst returnen
  else:
    return output                     # Anders return de (hopelijk) correct berekende startposities

# Functie oproepen
print startposities([(1,0),(3,1),(2,-1),(4,0)])
print startposities([(2,2),(8,0),(5,-2),(7,1),(1,1),(9,1),(3,-3)])
print startposities([(22,1),(9,1),(13,0),(21,-2)])
print startposities([(19,1),(9,-99),(17,0)])
