#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Student{
	char name[12];
	char id[12];
	int grade;
}stu[100];

bool cmp(Student a, Student b){
	return a.grade > b.grade;
}

int main (){
	int N;
	scanf("%d", &N);
	for (int i = 0;i < N;i++){
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}

	sort(stu, stu + N, cmp);

	bool flag = false;
	int gradeL, gradeR, num = 0;
	scanf("%d%d", &gradeL, &gradeR);
	for (int i = 0;i < N;i++){
		if (stu[i].grade <= gradeR && stu[i].grade >= gradeL){
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = true;
		}
	}

	if (flag == false){
		printf("NONE\n");
	}

	return 0;
}
