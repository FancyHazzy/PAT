#python 部分正确

nums = list(map(int,input().split()))
ans = ''
if (sum(map(lambda x:x*x,nums)) == 0) :
    print ('0 0')
else:

    if nums[-1] == 0:
        nums = nums[:-2]
        
    for i in range(len(nums)):
        if i % 2 == 0:
            nums[i] = nums[i] * nums[i+1]
        else:
            nums[i] = nums[i] -1
        ans = ans + str(nums[i]) + ' '
    print(ans[:-1])
    
    
---------------------------------------------------------------------
//c
#include<stdio.h>
int main(void)
{
	int a[1010] = {0};
	int k, e, count = 0;
	while(scanf("%d%d",&k, &e) != EOF)
	{
		a[e] = k;
	}

	a[0] = 0;
	for (int i = 1;i <= 1000;i++)
	{
		a[i-1] = a[i] * i;
		a[i] = 0;
		if(a[i-1] != 0) count++;//记录不为零的导数项个数
	}

	if(count == 0)printf("0 0");
	else{
		for (int i = 1000;i >= 0;i--)
		{
			if(a[i]!= 0)
			{
				printf("%d %d",a[i],i);
				count--;
				if (count!=0)printf(" ");
			}
		}
	}

	return 0;
}
