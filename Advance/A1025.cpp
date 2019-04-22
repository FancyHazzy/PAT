/*
思路：
1.用结构体 student 保存学生信息和排名并读取
2.首先对某考场内的学生进行排序，填写local_rank
3.然后对全部考生进行排序，一遍输出一遍排序
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct student{
    char id[15];
    int scores;
    int position_num;//考场号
    int local_rank;//考城内排名
}stu[30010];

bool cmp (student a, student b){
    if (a.scores != b.scores) return a.scores > b.scores;
    else return strcmp(a.id, b.id) < 0;
}

int main (void){

    int N,K;
    int num = 0;//总人数
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> K;
        for (int k = 1; k <= K;k++){
            scanf("%s%d", stu[num].id, &stu[num].scores);
            stu[num].position_num = i;
            num ++;
        }

        sort(stu+num-K, stu+num, cmp);//为该考场内进行排序，然后接下来进行排名
        stu[num-K].local_rank = 1;
        for (int j = num - K + 1; j < num; j++){
            if (stu[j].scores == stu[j - 1].scores)
                stu[j].local_rank = stu[j - 1].local_rank;
            else stu[j].local_rank = j - (num - K) + 1;
        }

    }

    printf("%d", num);
    sort(stu, stu + num, cmp);//全部排序

    int r = 1;
    for (int i = 0; i < num ;i++){
        if (stu[i].scores != stu[i-1].scores)
            r = i + 1;
        printf("\n%s", stu[i].id);
        printf(" %d %d %d", r, stu[i].position_num, stu[i].local_rank);
    }
    return 0;
}
