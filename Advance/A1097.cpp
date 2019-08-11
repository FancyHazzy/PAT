#include<bits/stdc++.h>
using namespace std;

struct node{
    int id, data, next_id;
    bool is_de ;
};

bool visit[10010] = {false};

int main (){
    int start, K;
    int tem_id, tem_data, tem_next_id;
    cin >> start >> K;
    node a[100010];
    vector<node> v, ans_1, ans_2;
    for (int i = 0; i < K; i++){
        scanf("%d%d%d", &tem_id, &tem_data, &tem_next_id);
        a[tem_id] = {tem_id, tem_data, tem_next_id, false};
    }
    for (int i = start; i != -1; i = a[i].next_id){
        v.push_back(a[i]);
    }
    for(int i = 0; i < v.size(); i++){
        if ( visit[abs(v[i].data)] == false){
            visit[abs(v[i].data)] = true;
        }else
        {
            ans_2.push_back(v[i]);
            v[i].is_de = true;
        }
    }

    for (int i = 0; i < v.size(); i++){
        if (v[i].is_de == false)
            ans_1.push_back(v[i]);
    }

    int i = 0;
    for (i = 0; i < ans_1.size() - 1; i++){
        if (ans_1[i].is_de == false)
            printf("%05d %d %05d\n", ans_1[i].id, ans_1[i].data, ans_1[i+1].id);
    }
    printf("%05d %d -1\n", ans_1[i].id, ans_1[i].data);


    if (ans_2.size() > 0){//判断是否ans_2长度是否大于零，可能不存在
        for (i = 0; i < ans_2.size() - 1; i++){
            printf("%05d %d %05d\n", ans_2[i].id, ans_2[i].data, ans_2[i+1].id);
        }
        
        printf("%05d %d -1", ans_2[i].id, ans_2[i].data);

    }
        
    


    return 0;
}
