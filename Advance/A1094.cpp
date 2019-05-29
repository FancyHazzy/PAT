#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 110;
vector <int> Node[maxn];
int n, m;//n个人，m个非叶节点
int LARGEST = 0;
int max_peoples[maxn] = {0};

void BFS(int index, int deep){
    max_peoples[deep]++;
    if (Node[index].size() == 0){
        return ;
    }
    for (int i = 0; i < Node[index].size();i ++){
        BFS(Node[index][i], deep + 1);
    }
}

int main (void){
    scanf("%d%d", &n, &m);
    int num_index, num_child;
    for (int i = 0 ;i < m;i++){
        scanf("%d%d", &num_index, &num_child);
        int tem_child;
        for (int j = 0; j < num_child;j++){
            scanf("%d", &tem_child);
            Node[num_index].push_back(tem_child);
        }
    }

    BFS(1, 1);
    int MAX_People = 0, MAX_deep = -1;
    for (int i = 1; i < maxn;i++){
        if (MAX_People < max_peoples[i] ){
            MAX_People = max_peoples[i];
            MAX_deep = i;
        }
    }

    printf("%d %d",MAX_People, MAX_deep );


    return 0;
}
