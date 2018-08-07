#include<stdio.h>
struct Student
{
	long long zkzh;
	int kszwh;
}stu[1001];

int main(void)
{
	int N,M,b,c,t;
	long long a;
	scanf("%d",&N);
	for (int i = 0;i < N ;i++)
	{
		scanf("%lld%d%d",&a,&b,&c);//读入数据
		stu[b].zkzh = a;
		stu[b].kszwh = c;
	}

	scanf("%d",&M);
	for (int i = 0;i < M;i++)
	{
		scanf("%d",&t);//t是待查询试机号
		printf("%lld %d", stu[t].zkzh,stu[t].kszwh);
		if (i < M-1)printf("\n");
	}
	return 0;
}
