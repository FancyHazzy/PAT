#include<stdio.h>
int main(void)
{
	float a[1010] = {0}, b[1010] = {0},c[2020] = {0};
	int a_len = 0,b_len = 0,e = 0,count = 0;
	float k = 0.0;
	scanf("%d",&a_len);
	for (int i = 0;i < a_len;i++)
		{
			scanf("%d%f",&e, &k);
			a[e] = k;
		}
	scanf("%d",&b_len);
	for (int i = 0;i < b_len;i++)
		{
			scanf("%d%f",&e, &k);
			b[e] = k;
		}
  
	for (int i = 0;i <= 1000;i++)
		for (int j = 0;j <= 1000;j++ )
			if(a[i] && b[j])
				c[i+j] += a[i] * b[j];

	for (int i = 0;i <= 2001;i++)
		if(c[i] != 0.0) count++;
	
	printf("%d",count);
	for(int i = 2000;i >= 0;i--)
		if(c[i] != 0)printf(" %d %.1f",i,c[i] );	

	return 0;
}	
