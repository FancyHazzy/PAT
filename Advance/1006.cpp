struct Node{
	char name[20];
	int in_time,out_time;
}temp;

#include<stdio.h>
int main (void)
{
	int M,MAX_in_time=235959,MAX_out_time=000000;
	int h1,h2,m1,m2,s1,s2;
	char early_name[20],lately_name[20];
	scanf("%d",&M);
	for (int i = 0;i < M ;i++)
	{
		scanf("%s%d:%d:%d %d:%d:%d",temp.name,&h1,&m1,&s1,&h2,&m2,&s2);
		temp.in_time = h1*10000+m1*100+s1;		
		temp.out_time = h2*10000+m2*100+s2;
		if (temp.in_time < MAX_in_time)
		{	
			MAX_in_time = temp.in_time;
			for (int j = 0;j < 20;j++)
				early_name[j] = temp.name[j];
		}
		if(temp.out_time > MAX_out_time)
		{	
			MAX_out_time = temp.out_time;
			for (int j = 0;j < 20;j++)
				lately_name[j] = temp.name[j];
		}

	}
  printf("%s %s", early_name,lately_name);
	return 0;
}
#
