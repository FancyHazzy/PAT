#include <stdio.h>

int main(void)
{
	int N = 54;//total num
	char mp[5] = {'S','H','C','D','J'};//记录花色
	int start[N+1], end[N+1], next[N+1];
	int K;
	scanf("%d",&K);
	for (int i = 1;i <= N;i++)
	{
		start[i] = i;//输入1-54
		scanf("%d",&next[i]);//读取操作序列
	}

	while(K--)
	{
		for (int i = 1;i <= N;i++)
			end[next[i]] = start[i];
		for (int i = 1;i <= N;i++)
			start[i] = end[i];
	}

	for (int i = 1;i <= N;i++)
	{
		if (i != 1)	printf(" ");
		printf("%c%d", mp[(start[i] - 1) / 13],(start[i] - 1) % 13 + 1);
		//13对13求模，需要-1+1
	}
	return 0;
}
