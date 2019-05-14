#
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 2010;

map<int, string> intToString;
map<string, int> stringToInt;
map<string, int> Gang;//head->人数
int G[maxn][maxn] = {0}, weight[maxn] = {0};//邻接矩阵，点权
int n, k, numPerson = 0;//边数，阈值k，总人数numPerson
bool vis[maxn] = {false};



void DFS(int v, int& head, int& numMember, int& totalValue){
    //DFS所有的人
    numMember ++;
    vis[v] = true;
    if (weight[v] > weight[head]){
        head = v;
    }
    for (int i = 0;i < numPerson;i++){
        if (G[i][v] > 0){
            totalValue += G[i][v];
            G[i][v] = G[v][i] = 0;//删除
            if (vis[i] == false)
                DFS(i, head, numMember, totalValue);
        }
    }
}

void DFSTrave(){
    for (int i = 0;i < numPerson;i++){
        if (vis[i] == false){
            int head = i, numMember = 0,totalValue = 0;//头目，成员数，总边权
            DFS(i, head, numMember, totalValue);//遍历i所在的连通块
            if (numMember > 2 && totalValue > k){
                Gang[intToString[head]] = numMember;
            }
        }
    }
}


int change(string s){
    if (stringToInt.find(s) != stringToInt.end()){
        return stringToInt[s];
    }else{
        stringToInt[s] = numPerson;
        intToString [numPerson] = s;
        return numPerson++;
    }
}

int main(void){
    string a, b;
    int w;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n;i++){
        cin >> a >> b >> w;
//        scanf("%s\n", a);
//        scanf("%s\n", b);
//        scanf("%d\n", &w);
        int id1 = change(a);
        int id2 = change(b);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();//遍历图中所有的连通块

    cout << Gang.size() << endl;
    map<string, int>::iterator it;
    for (it = Gang.begin();it != Gang.end();it++){
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}







