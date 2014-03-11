'''
Description:  Rondom tien
              Ik ga alle rijen inlezen en achter plakken, tot 1 grote lijn tekst. 
              Bij het inlezen van de eerste rij bepaal ik de lengte van zo'n rij.
              Merk op dat ik voor en achter elke rij een 0 plak, alsook boven en
              onder het hele rooster.
              Zo kunnen we makkelijk de randen van het rooster berekenen zonder
              al te veel controle in onze code.

              Grafisch voorbeeld van linksboven het gegeven rooster:
                  Q Y n .    0 0 0 0 .
                  b U f . => 0 Q Y n .  De rondomliggende getallen van Q kunnen nu
                  e n 2 .    0 b U f .  veel eenvoudiger gecontroleerd worden zonder
                  . . . .    0 e n 2 .  dat we controle moeten doen of we aan een rand
                             . . . . .  zitten van het rooster.

Input:        1. Aantal rijen (48)
              2. Heel het rooster (QYn..)

Output:       Verborgen bericht

Author:       Bart Volkaerts
Date:         4/11/2013
'''


# Invoeren van het getal dat het aantal rijen van het rechthoekig rooster bevat
size = int(raw_input())

# Invoeren van de eerste rij en de lengte van zo'n rij bepalen
text = '0' + str(raw_input()) + '0'
length = len(text)
# rest van de input wordt erachter geplakt
for _ in range(size-1):
  text += '0' + raw_input() + '0'

# een lijn met 0'en aanmaken met dezelfde lengte als 1 rij
line_zeros = ''
for _ in range(length):
  line_zeros += '0'

# de nullen boven en onder het rooster plakken
text = line_zeros + text + line_zeros

# Controleren op beschermde letters
word = ''
for i in range(1,size+1):       # size +1 door de nullen die we hebben toegevoegd  
  for j in range(1,length-1):   # length-1, want length is bepaald NADAT de nullen zijn toegevoegd
    sum = 0
    if not text[i*length +j].isdigit():     # kijken of het karakter op de huidige plaats een letter is (= NOT a digit)
      if(text[i*length + j -1].isdigit()):  # kijken naar het karakter links
        sum += int(text[i*length + j -1])
      if(text[i*length + j +1].isdigit()):  # kijken naar het karakter rechts
        sum += int(text[i*length + j +1])
      if(text[i*length + j -length].isdigit()): # kijken naar het karakter boven (Alles plakt achter elkaar, dus huidige plaats
                                                # min de lengte van de rij levert ons de plaats erboven op)
                                                # vb: 2 4 6 8
                                                #     a b c d => 2 4 6 8 a b c d (karakter 'boven' d, is plaats van d-4, is 8)
        sum += int(text[i*length + j -length])
      if(text[i*length + j +length].isdigit()): # kijken naar het karakter onder (zelfde als vorige, maar dan plus de lengte van een rij)
        sum += int(text[i*length + j +length])  
      
      if(sum == 10):  # als de som 10 is, letter toevoegen aan het woord
        word += text[i*length + j]

print word
