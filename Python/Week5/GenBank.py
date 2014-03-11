def genbank(m,n,s):
  length = len(s)   # lengte opvragen van de gekregen string
  temp = ''         # temp en i  aanmaken
  i = 0

  while i < length:           # zolang i (positie in de string) kleiner is dan de totale lengte
    temp = str(i+1) + ' '     # positie van de eerste letter en nodige spatie toevoegen aan temp string
    for k in range(n):            # k lus is verantwoordelijk voor het aantal blokken op een regel
      for l in range(m):          # l lus is verantwoordelijk voor de lengte van een blok
        if i == length:               # als i gelijk wordt aan lengte, hebben we alle tekens gehad. 
          k = n+1                     # We verhogen k zodat k buiten de range valt van n (en de loop dus ook stopt)
          break                       # we breaken uit de l-loop
        temp += str(s[i]).lower() # we voegen het karakater op de i-de plaats van s toe aan de temp string (in lowercase)
        i = i + 1                 # we verhogen i voor de controle
      temp += ' '                 # spatie tussen elk blok op dezelfde regel
    print temp
    



# Functie oproepen
genbank(4, 3, 'AGGCTGTCAATGCTAGGCATAgaagtcgTGCTGTAGagatagTCTGATAGTCGC')
print ' '
genbank(5, 2, 'GGATGCTGGTAGATCGATAT')
print ' '
genbank(10, 6, 'AGCT' * 252)
