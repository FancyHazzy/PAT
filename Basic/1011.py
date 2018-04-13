T = int ( input())
jg = []
for i in range(1, T + 1):
    A,B,C = list(map(int,input().split()))
    if A + B > C :
        jg.append('true')
    else:
        jg.append('false')
for i in range(1, T + 1):
    print ( 'Case #' + str(i) + ': ' + jg[i-1])
