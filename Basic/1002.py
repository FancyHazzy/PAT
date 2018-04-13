L = list( map( int, list(input())))
S = sum (L)
PY = ['ling','yi','er','san','si','wu','liu','qi','ba','jiu']
jg = ''
if S < 10:
    print (PY[S])
else:

    for i in str(S)[:-1]:
        jg = jg + PY[int (i)] + ' '
    jg = jg + PY[int(str(S)[-1])]
    print(jg)
