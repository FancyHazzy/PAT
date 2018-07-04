#include <stdio.h>
int main(void)
{
	int N,cntA = 0,cntB = 0;
	int A1,A2,B1,B2;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d%d",&A1,&A2,&B1,&B2);
		if (A1 + B1 == A2 && A1 + B1 != B2)
			cntB++;
		else if (A1 + B1 == B2 && A1 + B1 != A2)
			cntA++;

	}
printf("%d %d\n", cntA,cntB);

}
