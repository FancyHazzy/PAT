#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAX 10000
#define DMAX 10000
using namespace std;
typedef long long ll;
int m,k;
int main() {
    scanf("%d",&m);
    for(int i = 0;i < m;i ++) {
        scanf("%d",&k);
        int j;
        int c = 1;
        int ans = 0;
        for(j = (int)(log10(k) + 1);j > 0;j --) {
            c *= 10;
        }
        for(j = 1;j < 10;j ++) {
            ans = k * k * j;
            if(ans % c == k) break;
        }
        if(j < 10) printf("%d %d\n",j,ans);
        else puts("No");
    }
}
