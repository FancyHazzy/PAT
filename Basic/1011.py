#B1011.py
T = int ( input())
jg = []
for i in range(1, T + 1):
    A,B,C = list(map(int,input().split()))
    if A + B > C :
        jg.append('true')
    else:
        jg.append('false')
    print ( 'Case #' + str(i) + ': ' + jg[i-1])
    
----------------------------------------------------------------------------------------------------------------------------
//B1011.cpp
#include <stdio.h>
int main(void)
{
	int T ,tcase = 1;
	scanf("%d",&T);
	while(T--)
	{
		long long A,B,C;
		scanf("%lld%lld%lld",&A,&B,&C);
		if (A + B > C)
			printf("Case #%d: true\n",tcase++);
		else
			printf("Case #%d: false\n",tcase++);
	}

	return 0;
}
