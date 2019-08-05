#include<bits/stdc++.h>
//#define long long ll;
using namespace std;

struct node{
    int id, data, next_id;
};

int main (){

    int N, K;
    int s;//start
    int tem_start, tem_data, tem_next;
    cin >> s >> N >> K;
    node a[100010];
    vector<node> v, ans;//先把数据按顺序压入v， 然后按要求分成三类放入ans中
    for (int i = 0; i < N; i++){
        scanf("%d%d%d", &tem_start, &tem_data, &tem_next);
        a[tem_start] = {tem_start, tem_data, tem_next};
    }

    for (;s != -1; s = a[s].next_id){
        v.push_back(a[s]);
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].data < 0) ans.push_back(v[i]);

    for (int i = 0; i < v.size(); i++)
        if (v[i].data >= 0 && v[i].data <= K) ans.push_back(v[i]);

    for (int i = 0; i < v.size(); i++)
        if (v[i].data >= 0 && v[i].data > K) ans.push_back(v[i]);

    for (int i = 0; i < ans.size() - 1; i++){
        printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i+1].id);
    }
    printf("%05d %d -1", ans[ans.size()-1].id, ans[ans.size()-1].data);



    return 0;
}
