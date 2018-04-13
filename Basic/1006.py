num = int (input())
bai = int (num / 100)
shi = int ( (num / 10) % 10 )
ge = num % 10 
gs = ''
for i in range(1,ge+1):
    gs = gs + str (i)
print ( 'B'*bai + 'S'*shi + gs)
