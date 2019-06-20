#include<bits/stdc++.h>
using namespace std;
#define ll long long

char a[12], b[12];
int c[12];
int tag, radix;

int main (void){
    cin >> a >> b >> tag >> radix;
    if (tag == 2){
        swap(a, b);
    }
    long long Q1 = 0, Q2 = 0, product = 1;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int tem = 0;
    for (int i = len_a - 1; i >= 0; i--){
        if (a[i] >= 'a' && a[i] <= 'z'){
            tem = a[i] - 'a' + 10;
        }
        else if (a[i] >= '0' && a[i] <= '9'){
            tem = a[i] - '0';
        }
        Q1 = Q1 + tem * product;
        product *= radix;
    }

    for (int i = 0; i < len_b; i++){
        if (b[i] >= 'a' && b[i] <= 'z'){
            c[i] = b[i] - 'a' + 10;
        }else if(b[i] >= '0' && b[i] <= '9'){
            c[i] = b[i] - '0';
        }
       // printf("%d", c[i]);
    }
    //printf("%c", c[0]);
    product = 1;
    int left_num = 2, right_num = 36;
    int mid;
    while(left_num <= right_num){
        Q2 = 0;
        product = 1;
        mid = (left_num + right_num) / 2;
        for (int i = len_b - 1; i >= 0; i--){
            Q2 += c[i] * product;
            product *= mid;
        }
        //printf("Q2 = %ll\n", Q2);
        if (Q1 == Q2){
            printf("%d", mid);
            return 0;
        }else if (Q1 < Q2){
            right_num = mid - 1;
        }else if (Q1 > Q2){
            left_num = mid + 1;
        }

       // printf("%d-%d,", left_num, right_num);

    }
    if (left_num > right_num){
        printf("Impossible");
    }



    return 0;
}


