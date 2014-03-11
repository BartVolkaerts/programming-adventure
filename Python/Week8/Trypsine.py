'''
Description:  Trypsine
Author:       Bart Volkaerts
Date:         6/11/2013
'''

def trypsine(s):      # Functie om de eiwitsequentie af te knippen na elke R of K
  temp = ''           # Tijdelijke string
  lijst = []          # Nieuwe ijst
  for char in s:      # Voor elke letter in de eiwitsequentie
    temp += char      # Letter toevoegen aan string
    if char == 'R' or char == 'K':  # Als de letter die net toegevoegd is == K of R, woord toevoegen aan lijst en tijdelijke leegmaken
      lijst.append(temp)
      temp = ''
  if temp:            # Als we uit de for lus komen, maar er zitten nog letters in de string, ook toevoegen aan lijst.
    lijst.append(temp)# Het zijn de laatste letters waarvan de laatste niet eindigt op K of R
  return lijst        # Lijst returnen

def massaspectrometer(l):   # Functie om alle elementen tussen 5 en 50 en eindigend op K en R eruit te halen
  l = trypsine(l)           # Eerdere functie gebruiken om een lijst te maken van de eiwitsequentie
  lijst = []                # nieuwe lijst maken
  for element in l:         # voor elk element van de lijst gekregen van trypsine()
    if len(element) >= 5 and len(element) <= 50 and (element[-1] == 'K' or element[-1] == 'R'): # als >=5 <=50 en eindigend op K of R
      lijst.append(element)                                                                     # toevoegen aan nieuwe lijst
  return lijst

print trypsine('NRRPCHSHTKECESAWKNRPCHSHTKKPCHSHTKKNRKVWKIPPFFW')
print trypsine('HAEWTDNQCCPVLKECESAWKYEMWQHPGEQHKRRRYEMWQHPGEQHKPCHSHTKVWKRY')

print massaspectrometer('NRRPCHSHTKECESAWKNRPCHSHTKKPCHSHTKKNRKVWKIPPFFW')
print massaspectrometer('HAEWTDNQCCPVLKECESAWKYEMWQHPGEQHKRRRYEMWQHPGEQHKPCHSHTKVWKRY')
