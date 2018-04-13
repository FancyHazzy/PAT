L = list( input().split())
L.reverse()
temp = ''
for i in L[:-1]:
    temp = temp + i + ' '
  
temp = temp + L[-1]
print (temp)
  
