'''
Description:  ISBN
Author:       Bart Volkaerts
Date:         6/11/2013
'''

import re         # Nodig voor de reguliere expressie die ik gebruik

def testISBN(number):
  match = re.match(r'(\d)-(\d{4})-(\d{4})-(\d)$', number)   # kijken of de input van vorm x-xxxx-xxxx-x is
  if not match:                                             # Ik weet niet of je al reguliere expressies gezien hebt?
    return False

  i = 1
  som = 0
  for element in number[:-1]:     # elk karakter op de string apart bekijken
    if element.isdigit():         # kijken of het een cijfer is en geen streepje
      som += i*int(element)       # vermenigvuldigen met de plaats van het getal en optellen bij totale som
      i += 1

  if number[-1] == 'X':           # in de tekst staat dat het laatste getal een 10 (X) kan zijn, dus omzetten naar een 10
    controlenumber = 10
  else:
    controlenumber = int(number[-1])

  if (controlenumber == (som%11)):
    return True
  else:
    return False


# Functie oproepen
print testISBN('9-9715-0210-0')
print testISBN('997-150-210-0')
print testISBN('9-9715-0210-8')
