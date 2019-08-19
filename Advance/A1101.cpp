#include<bits/stdc++.h>
using namespace std;

map<int, int>v;
vector<int>a, b;
vector<int>ans;
int N;
int main(void){
    scanf("%d", &N);
    int tem;
    int cnt = 0, maxnum = 0;
    for (int i = 0; i < N; i++){
        scanf("%d", &tem);
        a.push_back(tem);
        b.push_back(tem);
    }
    sort(b.begin(), b.end());

    for (int i = 0; i < N; i++){
        if (a[i] == b[i] && a[i] > maxnum){
            cnt++;
            ans.push_back(b[i]);
        }
        if (a[i] > maxnum)
            maxnum = a[i];
    }

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");


    return 0;
}
 
