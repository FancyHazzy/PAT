#include <bits/stdc++.h>
using namespace std;
const int inf = 99999999;
int G[510][510];
int dis[510], weight[510];
vector <int> pre[510], path, temppath;
int Cmax, N, Sp, M;
bool visit[510] = {false};
int minneed = inf, minback = inf;

void dfs(int v){
    temppath.push_back(v);
    if (v == 0){
        int neednum = 0, backnum = 0;
        for (int i = temppath.size() - 1; i >= 0 ; i--){
            int id  = temppath[i];
            if (weight[id] > 0){
            	backnum += weight[id];
            }else {
            	if (backnum > 0 - weight[id]){
            		backnum += weight[id];
            	}else{
            		neednum += 0 - weight[id] - backnum;
            		backnum = 0;
            	}
            }
        }

        if (neednum < minneed){
        	minneed = neednum;
        	minback = backnum;
        	path = temppath;
        }else if (neednum == minneed && backnum < minback){
        	minback = backnum;
        	path = temppath;
        }
        temppath.pop_back();//回溯弹出
        return ;
    }
    for (int i = 0; i < pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main(void){
    cin >> Cmax >> N >> Sp >> M;
    fill(G[0], G[0] + 510*510, inf);
    //fill(weight, weight + 510, inf);
    fill(dis, dis + 510, inf);
    for (int i = 1; i <= N; i++){
        scanf("%d", &weight[i]);
        weight[i] = weight[i] - Cmax / 2;
    }
    int tem_a, tem_b;
    for (int i = 0; i < M; i++){
        scanf("%d%d", &tem_a, &tem_b);
        scanf("%d", &G[tem_a][tem_b]);
        G[tem_b][tem_a] = G[tem_a][tem_b];
    }

    dis[0] = 0;
    for (int i = 0; i < N; i++){
        int u = -1, minn = inf;
        for (int j = 0; j < N; j++){
            if (visit[j] == false && minn > dis[u]){
                u = j;
                minn = dis[j];
            }

        }

        if (u == -1) break;
        visit[u] = true;

        for (int v = 0; v <= N; v++){
            if (visit[v] == false && G[u][v] != inf){
                if (dis[u] + G[u][v] < dis[v]){
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[u] + G[u][v] == dis[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }

    dfs(Sp);

    printf("%d 0", minneed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minback);
    
    return 0;
}
