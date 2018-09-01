#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10010;

struct Student
{
	int user_id;
	int scores[6];//存储每道题的得分
	int perfect_num;
	int total_score;	
	bool flag;
}stu[maxn];

int full[6];
int N,K,M;
bool cmp(Student a, Student b){
	if (a.total_score != b.total_score) return a.total_score > b.total_score;
	else if (a.perfect_num != b.perfect_num) return a.perfect_num > b.perfect_num	;
	else return a.user_id < b.user_id;
}

void init(){
	for (int i = 1;i <= N;i++){
		stu[i].user_id = i;
		stu[i].total_score = 0;
		stu[i].perfect_num = 0;
		stu[i].flag = false;
		memset(stu[i].scores, -1, sizeof(stu[i].scores) );//初始化为-1
	}
}

int main (){
	scanf("%d%d%d",&N,&K,&M);
	init();
	for (int i = 1;i <= K;i++){
		scanf("%d",&full[i]);
	}
	int u_id, p_id, score_obtained;
	for (int i = 0;i < M;i++){
		scanf("%d%d%d",&u_id, &p_id, &score_obtained);
		if (score_obtained != -1){
			stu[u_id].flag = true;//有能过编译的题目
		}
		if (score_obtained == -1 && stu[u_id].scores[p_id] == -1){
			stu[u_id].scores[p_id] = 0;
		}
		if (score_obtained == full[p_id] && stu[u_id].scores[p_id]
			< full[p_id]){
			stu[u_id].perfect_num++;
		}
		if (score_obtained > stu[u_id].scores[p_id]){
			stu[u_id].scores[p_id] = score_obtained;
		}
	}

	for (int i = 1;i < N;i++){
		for (int j = 1;j <= K;j++){
			if (stu[i].scores[j] != -1)
				stu[i].total_score += stu[i].scores[j];
		}
	}

	sort(stu + 1, stu + N + 1, cmp);

	int r = 1;
	for (int i = 1; i <= N && stu[i].flag == true;i++){
		if (i > 1 && stu[i].total_score != stu[i-1].total_score){
			r = i;
		}
		printf("%d %05d %d", r, stu[i].user_id, stu[i].total_score);

		for (int j = 1;j <= K; j++){
			if (stu[i].scores[j] == -1){
				printf(" -");//没有提交
			}
			else {
				printf(" %d", stu[i].scores[j]);
			}

		}
		printf("\n");

	}

	return 0;
}
