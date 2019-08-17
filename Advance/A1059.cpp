#include<bits/stdc++.h>
using namespace std;
long int N, N2;
struct node{
    int di, zhi;
};

vector<node> a;

int main (void){
    cin >> N2;
    N = N2;
    if (N2 >= 1 && N2 <= 3){
        printf("%d=%d", N2, N2);
        return 0;
    }

    a.push_back({1, 0});
    long int sqrn = sqrt(N);
    for (int i = 2; i <= sqrn; i++){
        while (N % i == 0){
            if (a[a.size()-1].di != i){
                a.push_back({i, 1});
            }else{
                a[a.size()-1].zhi++;
            }
            N = N / i;
        }
    }

    cout << N2 << "=";

    for (int i = 1; i < a.size(); i++){
        if (i == 1){
            if (a[i].zhi == 1){
                printf("%d", a[i].di);
            }else{
                printf("%d^%d", a[i].di, a[i].zhi);
            }
        }

        else{

            if (a[i].zhi == 1){
                printf("*%d", a[i].di);
            }else{
                printf("*%d^%d", a[i].di, a[i].zhi);
            }
        }


    }



    return 0;
}
