#include<stdio.h>
int main (void)
{
	int school[100010] = {0};
	int k,N,MAX_S  = 0,MAX_K,s;
	scanf("%d",&N);
	for (int i = 1;i <= N ;i++)
	{
		scanf("%d%d",&k,&s);
		school[k] += s;
		if (school[k] > MAX_S)
		{
			MAX_S = school[k];
			MAX_K = k;
		}

	}
	printf("%d %d",MAX_K,MAX_S);
	return 0;
}
