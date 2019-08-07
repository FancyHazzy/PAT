#include<bits/stdc++.h>
using namespace std;
/*
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
*/
/*
2
9 4 6 7 2 8 1 9 5 3
NO
YES
*/
int main (){

    int M, N;

    scanf("%d", &M);
    while(M--){
        scanf("%d", &N);
        int flag = 1;
        int a[1010] = {0};
        for (int i = 1; i <= N; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= N; i++){
            for (int j = 1; j < i; j++){
                if (a[j] == a[i] || abs(a[i] - a[j]) == abs(i - j)){
                    flag = 0;
                    break;
                }
            }

            if (flag == 0){
                printf("NO\n");
                break;
            }

        }
        if (flag == 1){
            printf("YES\n");
        }


    }
    return 0;
}


//在数据处理的时候，要注意目前的读入状态，是否改组数据还有未读完的数据。
