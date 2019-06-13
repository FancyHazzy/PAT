#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
//题意：给出一个十进制数字N和一个进制D，该数字的D进制的反转数的十进制是否素数。
//注意点：
//1.判断素数中需要 if(n <= 1) return false;
//2.可以用数组存放，完成进制转化

int D, N;

bool isprime(int n){
    if (n <= 1) return false;
    int sq = int(sqrt(n * 1.0));
    for (int i = 2; i <= sq; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main (void){
    
    while(scanf("%d", &N) != EOF){//***
        if (N < 0) break;
        scanf("%d", &D);
        if (isprime(N) == false){
            printf("No\n");
            continue;
        }
        int len = 0, arr[100];
        do{
            arr[len++] = N % D;
            N = N / D;
        }while(N != 0);
        
        for (int i = 0; i < len; i++){
            N = N * D + arr[i];
        }
        printf("%s", isprime(N) ? "Yes\n" : "No\n");
    
        
    }
    return 0;
}
