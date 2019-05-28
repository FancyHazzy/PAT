#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
const int maxn = 100010;
vector <int> child[maxn];
double p, r;
int n, ans_num = 0;
double highest_price = 0;
int deepest = 0;

void DFS(int index, int deep){
    if (child[index].size() == 0){
       if (deep > deepest){
            deepest = deep;
            ans_num = 1;
        }else if (deep == deepest){
            ans_num++;
        }
        return ;
    }

    for (int i = 0;i < child[index].size();i++){
        DFS(child[index][i], deep + 1);
    }
}

int main(void){
    scanf("%d%lf%lf", &n, &p, &r);
    int tem_child, root;
    for (int i = 0; i < n; i++){
        scanf("%d", &tem_child);
        if (tem_child == -1){
            root = i;
        }else{
            child[tem_child].push_back(i);
        }
    }

    DFS(root, 0);
    r /= 100;
    highest_price = p * pow(1+r, deepest);
    printf("%.2lf %d",  highest_price, ans_num);

    return 0;
}
