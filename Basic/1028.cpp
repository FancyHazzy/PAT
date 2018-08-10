//C版本的第四个测试用例不通过

struct person_date{
  char name[6];
  long long born_date;
}oldest,youngest,temp,left,right;

#include<stdio.h>
int main(void)
{
	left.born_date = 18140906;
	youngest.born_date = 18140906;
	right.born_date = 20140906;
	oldest.born_date = 20140906;

	int N,count = 0;
	int yyyy,mm,dd;
	scanf("%d",&N);

  	for (int i = 0;i < N ;i++)
  	{
  		scanf("%s %d/%d/%d",temp.name,&yyyy,&mm,&dd);
  		temp.born_date = 10000 * yyyy + 100 * mm + dd;
  		if (temp.born_date >= 18140906 && temp.born_date <= 20140906)
  		{
	  		if (temp.born_date > youngest.born_date)
	  		{
	  			for (int i = 0;i < 6;i++)
	  				youngest.name[i] = temp.name[i];
	  			youngest.born_date = temp.born_date;
	  		}
	  		if (temp.born_date < oldest.born_date)
	  		{
	  			for (int i = 0;i < 6;i++)
	  				oldest.name[i] = temp.name[i];
	  			oldest.born_date = temp.born_date;
	  		}
	  		count ++;
  		}
  	}

  	if (count == 0)
  		printf("%d",count);
  	printf("%d %s %s", count,oldest.name,youngest.name);
  
	return 0;
}



-----------------------------------------
#python 版本的最后一个测试用例超时
N = int(input())
L = []
youngest = 18140906
oldest = 20140906
count = 0
for i in range(N):
  info = input()
  temp = info[:-6] + info[-5:-3] + info[-2:]
  if 18140906<= int(temp[-8:0])<=20140906:
    if int(temp[-8:0]) >= int(youngest[-8:0]):
      youngest = temp
    if int(temp[-8:0]) <= int(oldest[-8:0]):
      oldest = temp
    count += 1
if (count == 0):
	print(0)
else:
	print (count + ' ' + oldest[:-8] + ' ' + youngest[:-8])
