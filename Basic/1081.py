
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
import string
N = int (input())
for i in range(N):
    pwd = input()
    digit_flag = letter_flag = dian_flag = illegal_flag = 0
    for j in range(len(pwd)):
        if pwd[j] in string.digits:
            digit_flag += 1
        elif pwd[j] in string.ascii_letters:
            letter_flag += 1
        elif pwd[j] == '.':
            dian_flag += 1
        else :
            illegal_flag = 1

    if digit_flag + letter_flag + dian_flag < 6:
        print ('Your password is tai duan le.')
    elif illegal_flag:
        print ('Your password is tai luan le.')
    elif letter_flag and digit_flag == 0 :
        print ('Your password needs shu zi.')
    elif digit_flag and letter_flag == 0 :
        print ('Your password needs zi mu.')
    else :
        print ('Your password is wan mei.')
        
