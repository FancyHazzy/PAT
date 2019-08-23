#include<bits/stdc++.h>
using namespace std;

struct node{
    char name[10];
    int height;
};

node stu[10010];

bool cmp(node a, node b){
    if (a.height != b.height){
        return a.height > b.height;
    }else{
        return strcmp(a.name, b.name) < 0;
    }
}

void printrow(int a, int b){
    vector<node>v;
    int flag = 0;
    for (int i = a; i <= b; i++){
        if (flag == 0){
            v.push_back(stu[i]);
            flag = 1;
        }else{
            v.insert(v.begin(), stu[i]);
            flag = 0;
        }
    }
    for (int i = 0; i < v.size(); i++){
        if (i == 0){
            printf("%s", v[i].name);
        }else{
            printf(" %s", v[i].name);
        }
        
    }
}


int main(void){
    int N, K, rows;
    //int length_every_row[20];
    cin >> N >> K;
    rows = N / K;
    for (int i = 1; i <= N; i++){
        scanf("%s %d", stu[i].name, &stu[i].height);
    }
    int last_row = N - (N / K) * (K - 1);
    sort(stu + 1, stu + N + 1, cmp);
    int length_every_row = N / K;
    int st, en;
//    for (int i = 1; i <= N; i++){
//        printf("%s %d\n", stu[i].name, stu[i].height);
//    }


    for (int i = 1; i <= K; i++){
        if (i == 1){
            printrow(1, last_row);
        }
        else{
            printf("\n");
            printrow(last_row + 1, last_row + length_every_row);
            last_row += length_every_row;
        }
    }

   return 0;
}
