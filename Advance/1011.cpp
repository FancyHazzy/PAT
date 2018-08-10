#include<stdio.h>
int main (void)
{
	float MAX[5]={0.0},temp[5];
	char SELECT[5],SELECTS[4] = {' ','W','T','L'};
	float total;
	for (int i = 1;i <= 3 ;i++)
	{
		scanf("%f%f%f",&temp[1],&temp[2],&temp[3]);
		for (int j = 1;j <= 3 ;j++)
		{
			if (MAX[i] < temp[j])
			{
				MAX[i] = temp[j];
				SELECT[i] = SELECTS[j];
			}
		}
	}

	total = (MAX[1]*MAX[2]*MAX[3]*0.65 - 1)*2;
	printf("%c %c %c %.2f",SELECT[1],SELECT[2],SELECT[3],total );

	return 0;
}

