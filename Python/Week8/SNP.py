'''
Description:  SNP(s)
Author:       Bart Volkaerts
Date:         6/11/2013
'''

def SNP(str1,str2):           #SNP functie. Vergelijk 2 evenlange strings en kijk waar het verschil zit
  if len(str1) != len(str2):  # Als ze niet evenveel tekens bevatten meteen returnen.
    return None

  fouten = 0                  # Variabele voor het aantal fouten in de te bekijken strings (str1 en str2)
  for i in range(len(str1)):  # Van 0 tot 6. (range(7))
    if str1[i] != str2[i]:    # Als de letters verschillend zijn:
      fouten += 1               # Fouten + 1
      plaats = i                # plaats bijhouden. Moet geen lijst zijn. We zijn op zoek naar 1 fout en dus 1 plaats.

  if fouten == 1:             # als het totaal aantal fouten == 1, weten we dat de plaats ook correct is
    return (plaats, str1[plaats], str2[plaats]) # tuple returnen van (plaats, letter uit str1, letter uit str2)
  else:
    return None               # Als er 0 of meerdere fouten waren None returnen


def SNPs(genoom, read):       # SNPs functie. Neemt een read waarde, en 'schuift' deze langs de genoom, zodat we elke plaats hebben gehad
  lijst = []                  # nieuwe lijst aanmaken
  length_g = len(genoom)      # lengtes berekenen
  length_r = len(read)

  for i in range(length_g-length_r+1):  # van 0 tot lengte_genoon-lengte_read +1. We doen +1 omdat we beginnen vanaf 0.
    str1 = genoom[i:length_r+i]         # str1 krijgt de tekens van de genoom beginnend vanaf plaats i tot lengte_r+i. 
                                        # Schuiven elke iteratie 1 plaats op
    tuples = SNP(str1, read)  # Tuples opvangen die SNP functie ons geeft
    if not (tuples == None):  # Alleen iets doen als de tuple geen None was
      lijst.append(tuples[0]+i) # we hebben alleen het eerste veld nodig van de tuple die SNP terug gaf, nl de plaats
  
  return lijst          # we returnen de lijst

#Functie oproepen
print SNP('AAGCCTA', 'AAGCTTA')
print SNP('AAGCCTAA', 'AAGCTTA')
print SNP('AAGCTTA', 'AAGCTTA')
print SNP('AAGCCCA', 'AAGCTTA')

print SNPs('AGCTGATAAGCCTAAGCGCT', 'AAGCTTA')
print SNPs('ATCGTAAGCCTAAGGCTACGCTTAGAGATA', 'AAGCTTA')
print SNPs('AAGCCTAAGCCTA', 'AAGCTTA')
