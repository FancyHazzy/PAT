N = int (input())

def is_prime(num):
	if num in [2,3]:
		return 1
	else :
		for i in range(2, (num/2)+1 ):
			if num % 2 == 0:
				return 0
		return 1



num = 2
a = 2
ans = 0
  
while (num<=N):
	if is_prime(num):
		if (num - a == 2):
			ans += 1
		a = num
	num += 2
	
print(ans)
