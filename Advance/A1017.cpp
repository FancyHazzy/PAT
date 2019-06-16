//题意：有 n 个客户， k 个窗口。窗口开放时间为8点到17点。每个客户有到达时间和占用时间
//思路：用 vector<node>custmer 存放客户，先按到达时间进行排序。
//      用 vector<int>window 存放窗口开放时间，初始值为8点
//      循环每个客户，循环找到当前开放时间最早的窗口，
//          然后比较开放时间和客户到达时间：如果小于，同步到客户时间；如果大于，时间差计入等待时间。
//注意点：数据结构的选取，本例中选用 vector 即可。可以先将时间换算成秒来计算。

#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct node{
    int come_time;
    int work_time;
}temcustmer;
int n, k;
const int OPEN_TIME = 8 * 3600;
const int CLOSE_TIME = 17 * 3600;

vector<node> custmer;

bool cmp (node a, node b){
    return a.come_time < b.come_time;
}

int main(void){
    scanf("%d%d", &n, &k);
    int h, m, s;
    int come_time, work_time;
    for (int i = 0; i < n; i++){
        scanf("%d:%d:%d%d", &h, &m, &s, &work_time);
        come_time = h * 3600 + m * 60 + s;
        work_time = work_time * 60;
        if (come_time > CLOSE_TIME) continue;
        temcustmer = {come_time, work_time};
        custmer.push_back(temcustmer);
    }

    sort(custmer.begin(), custmer.end(), cmp);

    vector <int> window(k, OPEN_TIME);
    double ans = 0.0;
    for (int i = 0; i < custmer.size(); i++){
        int mintime = window[0], minindex = 0;
        for (int j = 1; j < k; j++){
            if (mintime > window[j]){
                minindex = j;
                mintime = window[j];
            }
        }//寻找最早开始时间

        if (window[minindex] > custmer[i].come_time){
            ans += (window[minindex] - custmer[i].come_time);
            window[minindex] += custmer[i].work_time;
        }
        else{
            window[minindex] = custmer[i].come_time + custmer[i].work_time;
        }
    }

        if (custmer.size() == 0){
            printf("0.0");
        }
        else{
            printf("%.1f", ans / 60 / custmer.size());
        }




    return 0;
}
