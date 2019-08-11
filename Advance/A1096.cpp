#include<bits/stdc++.h>
using namespace std;

int main (){
    int N;
    scanf("%d", &N);
    int cnt = 0, first = 0, maxn = sqrt(N) + 1;
    for (int i = 2; i <= maxn; i++){
        int j;
        int temp = 1;
        for (j = i; j <= maxn; j++){
            temp *= j;
            if (N % temp != 0) break;
        }
        if (j - i > cnt){
            cnt = j - i;
            first = i;
        }
    }
    if (cnt == 0){
        printf("1\n%d", N);
    }else{
        cout << cnt << endl;
        printf("%d", first);
        for (int i = 1; i < cnt; i++){
            printf("*%d", first + i);
        }
    }



    return 0;
}
//不断构造连续因子队列，判断是否能够整除，更新最长的连续队列长度即第一个数字。
