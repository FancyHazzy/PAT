#include<bits/stdc++.h>
#include<string>
#include<iostream>
using namespace std;
struct node{
    int poptime, endtime;
    queue<int> q;
};


int main(void){
    int N, M, K, Q;
    int index = 1;//客户的序号
    cin >> N >> M >> K >> Q;
    vector <node> windows(N+1);
    vector <int> Time(K+1);
    vector <int> result(K+1);
    vector <bool> sorry(K+1, false);
    for (int i = 1; i <= K; i++){
        scanf("%d", &Time[i]);
    }

    for (int i = 1; i <= M; i++){
        for (int j = 1; j <= N; j++){
            if (index <= K){
                windows[j].q.push(Time[index]);//将第 index 位客户的用时入队
                if (windows[j].endtime >= 540){
                    sorry[index] = true;
                }
                windows[j].endtime += Time[index];
                if (i == 1){
                    windows[j].poptime = windows[j].endtime;//poptime 记录该队列的队首出队时间
                }
                result[index] = windows[j].endtime;
                index++;
            }
        }
    }

    while (index <= K){
        int tem_min = windows[1].poptime, tem_window = 1;
        for (int i = 2; i <= N; i++){
            if (tem_min > windows[i].poptime){
                tem_min = windows[i].poptime;
                tem_window = i;//窗口号
            }
        }
        windows[tem_window].q.pop();
        windows[tem_window].q.push(Time[index]);//把等待区的下一个客户入队
        //windows[tem_window].poptime += Time[index];//此处应该是队首的时间
        windows[tem_window].poptime += windows[tem_window].q.front();
        if (windows[tem_window].endtime >= 540){
            sorry[index] = true;
        }
        windows[tem_window].endtime += Time[index];
        result[index] = windows[tem_window].endtime;
        index++;

    }

    for (int i = 1; i <= Q; i++){
        int query;
        scanf("%d", &query);
        int minute = result[query];
        if (sorry[query] == true){
            printf("Sorry\n");
        }else
        {
            printf("%02d:%02d\n", 8+ minute / 60, minute % 60);
        }
    }
    return 0;
}
