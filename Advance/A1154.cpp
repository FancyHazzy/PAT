#include<bits/stdc++.h>
//#define long long ll;
using namespace std;

struct node{
    int v1, v2;
};
int N, M, K;

int main(){
    scanf("%d%d", &N, &M);//N个顶点，M个边
    vector<node>G(M);
    int a, b, tem_color;
    for (int i = 0; i < M; i++)
        scanf("%d%d", &G[i].v1, &G[i].v2);
        
    scanf("%d" , &K);
    for (int i = 0; i < K; i++){
        int a[10005] = {0};
        bool flag = false;
        set<int> se;
        for (int j = 0; j < N; j++){
            scanf("%d", &a[j]);
            se.insert(a[j]);
        }
        for (int j = 0; j < M; j++){
            if(a[G[j].v1] == a[G[j].v2]){
                flag = true;
                break;
            }
        }
        if (flag){
            printf("No\n");
        }
        else{
            printf("%d-coloring\n", se.size());
        }
        
    }
    return 0;
}

//将边存下来，把顶点颜色也存下来，然后遍历边即可
//不需要使用vector存整个图


