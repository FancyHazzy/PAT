//1.使用cnt变量计数，最后一个不输出空格。
//2.M==0时直接输出数组即可
//3.M = M % N

#include <stdio.h>
int main(void)
{
	int N,M;
	int a[110],cnt = 0;
	scanf("%d%d",&N,&M);
	M = M % N;
	for (int i = 0;i < N;i++)
		scanf("%d",&a[i]);
	if (M == 0)
	{
		for (int i = 0,count = 1;i < N;i++,count++)
			if (count < N)
				printf("%d ", a[i]);
			else
				printf("%d", a[i]);
	}
	else
	{
		for (int i = N - M;i < N;i++)
		{
			printf("%d", a[i]);
			cnt++;
			if (cnt < N) printf(" ");
		}

		for (int i = 0;i < N - M;i++)
		{
			printf("%d", a[i]);
			cnt++;
			if (cnt < N) printf(" ");
		}
	}


	return 0;
}
