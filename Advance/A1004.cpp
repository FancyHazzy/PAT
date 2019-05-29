#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 110;
int n, non_leaf;
vector<int> G[maxn];
int ans_num_leaf[maxn] = {0};
int max_h = 0;

void DFS(int index, int deep){
    max_h = max(max_h, deep);
    if (G[index].size() == 0){
        ans_num_leaf[deep]++;
        return ;
    }else{
        for (int i = 0;i < G[index].size();i++){
            DFS(G[index][i], deep + 1);
        }
    }
}


int main (void){
    scanf("%d%d", &n, &non_leaf);
    int child_index, num_child, tem_child;
    for (int i = 0;i < non_leaf;i++){
        scanf("%d%d", &child_index, &num_child);
        for (int j = 0;j < num_child; j++){
            scanf("%d", &tem_child);
            G[child_index].push_back(tem_child);
        }
    }

    DFS(1, 1);

    printf("%d", ans_num_leaf[1]);

    for (int i = 2; i <= max_h ; i++){
        printf(" %d", ans_num_leaf[i]);
    }


    return 0;
}

/*
3 2
1 1 2
2 1 3
*/
