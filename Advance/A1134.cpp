#include<bits/stdc++.h>
using namespace std;

//vector 存边,对边进行编号。

int main (){
    int N, M, K, a, b, c;

    scanf("%d%d", &N, &M);
    vector<int> G[N];

    for (int i = 0; i < M; i++){
        scanf("%d%d", &a, &b);
        G[a].push_back(i);
        G[b].push_back(i);
    }
    scanf("%d", &K);
    while(K--){
        bool query[10010] = {false};
        scanf("%d", &c);
        int tem;
        int flag = 1;
        for (int i = 0; i < c; i++){
            scanf("%d", &tem);

            for (int j = 0; j < G[tem].size(); j++){
                query[G[tem][j]] = true;
            }

        }
        for (int i = 0; i < M; i++){
            if (query[i] == false){
                printf("No\n");
                flag = 0;
                break;
            }
        }
        if (flag)printf("Yes\n");

    }



    return 0;
}
