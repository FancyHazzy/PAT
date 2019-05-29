#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;
const int maxn = 100010;
const double INF = 1e12;
vector <int> Node[maxn];
double p, r;
int n, ans_num = 0, ans_deep = INF;


/*
void BFS(int index, int deep){
    q.push(index);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if (Node[index].size() == 0){
            ans_deep = deep;
            //return ;
        }
        if (Node[index].size() > 0){
            for (int i = 0; i < Node[index].size();i++){
                q.push(Node[index][i]);
            }
            deep++;
        }
    }
}
*/

void DFS(int index, int deep){
    if (Node[index].size() == 0){
        if (deep < ans_deep){
            ans_deep = deep;
            ans_num = 1;
        }else if (deep == ans_deep){
            ans_num++;
        }
        return ;
    }

    for (int i = 0;i < Node[index].size();i++){
        DFS(Node[index][i], deep + 1);
    }
}




int main (void){
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;
    int num_child, tem_child;
    for (int i = 0;i < n;i++){
        scanf("%d", &num_child);
        for (int j = 0; j < num_child;j++){
            scanf("%d", &tem_child);
            Node[i].push_back(tem_child);
        }
    }

    DFS(0, 0);

    double ans_price = p * pow(1 + r, ans_deep);
    //printf("ans_deep: %lf\n", ans_deep);
    //printf("%d %d\n", Node[1][0],Node[6][0]);
    printf("%.4lf %d", ans_price, ans_num);

    return 0;

}
/*
14 1.80 1.00
3 2 3 5
1 9
1 4
1 7
10
2 6 1
1 8
11
0
0
1 12
1 13
0
0
*/



