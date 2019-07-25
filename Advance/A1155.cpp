#include<bits/stdc++.h>
//#define long long ll;
using namespace std;
/*
input
8
10 28 15 12 34 9 8 56
output
10 15 8
10 15 9
10 28 34
10 28 12 56
Not Heap
*/
int flag = 1;//-1代表小根堆，1代表大根堆，0代表不是堆
int a[1010] = {-1};
int N, h = 0;

void print_a_to_b(int index_a, int index_b){
    vector<int>G;
    while(index_a >= index_b){
        int i = index_a;
        while(i >= 1){
            G.push_back(a[i]);
            i = i / 2;
        }
        if (flag){
            for (int j = 1; j < G.size(); j++){
                if ((G[j] - G[j - 1]) * flag < 0) {
                    flag = 0;
                    break;
                }
            }
        }

        printf("%d", a[1]);
        for (int j = G.size()-2; j >= 0; j--){
            printf(" %d", G[j]);
        }

        printf("\n");
        index_a--;
        G.clear();
    }
}

int main (){

    bool flag_2 = false;//false代表为完美二叉树
    scanf("%d", &N);

    for (int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
    }



    if (a[1] < a[N]) flag = -1;

    for (int j = 1; j < 12; j++){
        int s = pow(2, j) - 1;
        if (N <= s){
            h = j;
            if (s - N >= 2) flag_2 = true;//true代表为完整二叉树
            break;
        }
    }

    int index_a, index_b, index_c, index_d;
    if (flag_2){
        index_a = pow(2, h - 1) - 1;
        index_b = N / 2 + 1;
        index_c = N;
        index_d = index_a + 1;
        print_a_to_b(index_a, index_b);
        print_a_to_b(index_c, index_d);
    }
    else{
        index_a = N;
        index_b = pow(2, h - 1);
        print_a_to_b(index_a, index_b);
    }

    if (flag == 1){
        printf("Max Heap");
    }else if(flag == -1){
        printf("Min Heap");
    }else if(flag == 0){
        printf("Not Heap");
    }

    return 0;
}
