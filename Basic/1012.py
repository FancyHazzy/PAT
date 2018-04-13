L = list(map(int,input().split()))
A1 = A2 = A3 = A4 = A5 = S3 = count3 = n =0
m1 = m2 = m3 =  m5 = 'N'
for i in range(1,L[0] + 1):
    if ( L[i] % 10 == 0):
        A1 = A1 + L[i]
        m1 = A1
    elif (L[i] % 5 == 1):
        A2 = A2 + pow(-1,n) * L[i]
        m2 = A2
        n = n + 1
    elif (L[i] % 5 == 2):
        A3 = A3 + 1
        m3 = A3
    elif (L[i] % 5 == 3):
        S3 = S3 + L[i]
        count3 = count3 + 1
      
    elif (L[i] % 5 == 4 ):
        A5 = max(A5,L[i])
        m5 = A5
cc = ['N',1]
if count3 == 0 :
    A4 = 'N'
else :
    A4 = ("%.1f" % (S3 / count3))

print (m1,m2,m3,A4,m5)
