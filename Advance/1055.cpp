#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Person{
	char name[10];
	int age,worth; 	
}ps[100010], valid[100010];


bool cmp(Person a, Person b){
	if (a.worth != b.worth) return a.worth > b.worth;
	else if (a.age != b.age) return a.age < b.age;
	return strcmp (a.name, b.name) < 0;//按照字典序从小到大排序
}

int Age[100010] = {0};

int main(void){
	int N, K;
	scanf("%d%d",&N, &K);
	for (int i = 0;i < N;i++){
		scanf("%s%d%d",ps[i].name, &ps[i].age, &ps[i].worth);
	}

	sort (ps, ps + N, cmp);//sort

	int validNUM = 0;
	for (int i = 0;i <= N;i++){
		if ( Age[ps[i].age] < 100 ){
			Age[ps[i].age]++;
			valid[validNUM++] = ps[i];//添加到新数组中
		}
	}

	int M, ageL, ageR;
	for (int i = 1;i <= K;i++){
		scanf("%d%d%d",&M, &ageL, &ageR);
		printf("Case #%d:\n", i);
		int printNum = 0;//已经输出的人数
		for (int j = 0;j < validNUM && printNum < M;j++){
			if (valid[j].age >= ageL && valid[j].age <= ageR){
				printf("%s %d %d\n",valid[j].name, valid[j].age, 
					valid[j].worth);
				printNum++;//已经输出的人数
			}
		}

		if (printNum == 0){
			printf("None\n");
		}
	}
	return 0;
}
