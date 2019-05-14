#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXV = 1010;

struct node {
    int id;
    int layer;
};
vector<node> Adj[MAXV];
bool inq[MAXV] = {false};//记录顶点是否已经被加入队列

int BFS(int v, int L){
    //相当于写一个广搜遍历
    int numForward = 0;
    queue <node> q;//辅助队列
    node start;
    start.id = v;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while (!q.empty()){
        node topNode = q.front();
        q.pop();
        for (int i = 0; i < Adj[topNode.id].size();i++){
            node next = Adj[topNode.id][i];
            next.layer = topNode.layer + 1;
            if (inq[next.id] == false && next.layer <= L){
                q.push(next);
                inq[next.id] = true;
                numForward++;
            }
        }
    }
    return numForward;


}


int main(void){
    int n, L, numFollow, idFollow;//numFollow 是关注人数, idFollow 是关注的id
    scanf("%d%d", &n, &L);
    node user;
    for (int i = 1;i <= n;i++){
        user.id = i;
        scanf("%d", &numFollow);
        for (int j = 0;j < numFollow;j++){
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);
    for (int i = 0;i < numQuery;i++){
        //查询
        memset(inq, false, sizeof(inq));
        scanf("%d", &s);
        int numForward = BFS(s, L);//查询id和转发层数
        printf("%d\n", numForward);
    }




    return 0;

}
