def groepen(motief):
  lijst = motief.replace('{',',{').replace('}','},').replace('[',',[').replace(']','],').replace('x',',x,').split(',')
  lijst = [x for x in lijst if x != '']
  lijst2 = []
  for element in lijst:
    if element[0] != "{" and element[0] != "[":
      for element2 in list(element):
        lijst2.append(element2)
    else:
      lijst2.append(element)

  return len(lijst2)

def match(string, motief):
  lijst = motief.replace('{',',{').replace('}','},').replace('[',',[').replace(']','],').replace('x',',x,').split(',')
  lijst = [x for x in lijst if x != '']
  lijst2 = []
  for element in lijst:
    if element[0] != "{" and element[0] != "[":
      for element2 in list(element):
        lijst2.append(element2)
    else:
      lijst2.append(element)
  iterator = 0

  for element in string:
    if lijst2[iterator][0] == '{':
      if element in lijst2[iterator]:
        return False
    elif lijst2[iterator][0] == '[':
      if element not in lijst2[iterator]:
        return False
    elif lijst2[iterator][0] == 'x':
      iterator += 1
      continue
    else:
      if element != lijst2[iterator]:
        return False

    iterator += 1
  return True


print match('EVCIAWQ', '[GEVPST]{FMITQPL}{ET}[LENIFC]AW{ASVEFD}')
