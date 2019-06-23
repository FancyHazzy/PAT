#include<bits/stdc++.h>
using namespace std;

char arr[85];

int main (void){
    cin >> arr;
    int N = strlen(arr);
    int a, b;
    int n1, n2, n3;
    a = ((N + 2) / 3.0) > ((N + 2) / 3) ? ((N + 2) / 3 + 1) : ((N + 2) / 3);
    b = ((N + 8) / 3.0) > ((N + 8) / 3) ? ((N + 8) / 3) : ((N + 8) / 3 - 1);
    
    if (b % 2 == 0){
        swap(a, b);
    }

    if (N % 2 == 0){
        n2 = a;
    }else{
        n2 = b;
    }
    n1 = (N - n2 + 2) / 2;
    //printf("n1:%d n2:%d\n", n1, n2);
    for (int i = 0; i < n1-1; i++){
        printf("%c", arr[i]);
        for (int j = 0; j < n2 - 2; j++){
            printf(" ");
        }
        printf("%c\n", arr[N-1-i]);
    }
    for (int i = n1 - 1; i < n1 + n2 - 1; i++){
        printf("%c", arr[i]);
    }

    return 0;
}
