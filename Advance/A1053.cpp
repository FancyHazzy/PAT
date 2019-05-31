#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 110;
struct node{
    int weight;
    vector <int> child;
}Node[maxn];

int n, m, s;
int path[maxn];

bool cmp(int a, int b){
    return Node[a].weight > Node[b].weight;
}

void DFS(int index, int numNode, int cur_sum){
    if (cur_sum > s){
        return ;
    }
    if (cur_sum == s){
        if (Node[index].child.size() != 0) return;
        for (int i = 0; i < numNode; i++){
            printf("%d", Node[path[i]].weight);
            if (i < numNode - 1) printf(" ");
            else printf("\n");
        }
        return;
    }

    for (int i = 0; i < Node[index].child.size(); i++){
        int tem_child = Node[index].child[i];
        path[numNode] = tem_child;//新添加路径
        DFS(tem_child, numNode + 1, cur_sum + Node[tem_child].weight);
    }

}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    int id, k, child;
    for (int i = 0; i < n; i++){
        scanf("%d", &Node[i].weight);
    }
    for (int i = 0; i < m; i++){
        scanf("%d%d", &id, &k);
        for (int j = 0; j < k; j++){
            scanf("%d", &child);
            Node[id].child.push_back(child);
        }

        sort(Node[id].child.begin(), Node[id].child.end(), cmp);

    }


    path[0] = 0;

    DFS(0, 1, Node[0].weight);


    return 0;
}
