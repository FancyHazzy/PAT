n = int (input())
L = []
for i in range(n):
    a = input().split(' ')
    L = L + a
max_num = max(list(map(int,L[2::3])))
min_num = min(list(map(int,L[2::3])))

print (L[L.index(str(max_num)) - 2] + ' ' + L[L.index(str(max_num)) - 1])
print (L[L.index(str(min_num)) - 2] + ' ' + L[L.index(str(min_num)) - 1])
#
