struct stu{
	char name[15];
	char ID[15];
	int grade ;
}temp,highest,lowest;

#include<stdio.h>
int main (void)
{
	highest.grade = -1;
	lowest.grade = 101;
	char gender;
	int N;
	scanf("%d",&N);
	for (int i = 0;i < N ;i++)
	{
		scanf("%s %c %s %d",temp.name,&gender,temp.ID,&temp.grade);
		if(gender == 'F' && (temp.grade > highest.grade))
			highest = temp;
		else if (gender == 'M' && (temp.grade < lowest.grade ))
			lowest = temp;
	}
	if (highest.grade == -1 )printf("Absent\n");
	else printf("%s %s\n",highest.name,highest.ID);
	if (lowest.grade == 101 )printf("Absent\n");
	else printf("%s %s\n",lowest.name,lowest.ID);
	if (highest.grade == -1 || lowest.grade == 101)printf("NA");
	else printf("%d",highest.grade - lowest.grade);
	return 0;
}//
