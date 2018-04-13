N = int(input())
max_dis  = 0
min_dis = 1111111111
for i in range(N):
    ID,X,Y = input().split()
    dis = int(X)*int(X) + int(Y)*int(Y)
    if dis > max_dis:
        max_dis = dis
        cn = ID
    if dis < min_dis:
        min_dis = dis
        gj = ID
print (gj ,cn)
