#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100010;
struct node{
    double data;
    vector<int> child;
}Node[maxn];

int n;
double p, r, ans = 0;

void DFS(int index, int deepth){
    if (Node[index].data != -1){
        ans += pow(1 + r, deepth) * Node[index].data;
        return ;
    }
    for (int i = 0;i < Node[index].child.size();i++){
        DFS(Node[index].child[i], deepth + 1);
    }
}


int main (void){
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int num_child, tem_child;
    for (int i = 0; i < n;i++){
        scanf("%d", &num_child);
        if (num_child == 0){
            scanf("%d", &tem_child);
            Node[i].data = tem_child;

        }
        else{
            for (int j = 0;j < num_child;j++){
                scanf("%d", &tem_child);
                Node[i].data = -1;
                Node[i].child.push_back(tem_child);
            }
        }
    }

    DFS(0, 0);
    printf("%.1lf", ans * p);

    return 0;
}
