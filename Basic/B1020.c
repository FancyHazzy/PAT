#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) // 比较函数
{
    double *c = (double*)a, *d = (double*)b; 
    return c[0]*d[1]-c[1]*d[0];
}

int main()
{
    int n = 0, target = 0, ver = -1;
    scanf("%d %d", &n, &target);
    double rest = 0, sale[2] = {0}, price[n][2]; // sale[0]表示库存，sale[1]表示售价。

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", price[j]+i);

    qsort(price, n, 2*sizeof(double), comp);

    for (int i = 0; i < n && ver == -1; i++) {
        if (sale[0] + price[i][0] <= target) // 当前已售出库存+下一种月饼总库存会超过目标销量时，退出循环
            for (int j = 0; j < 2; j++)
                sale[j] += price[i][j]; // 销量与售价同时累加
        else
            ver = i; // 对于不能清空库存而退出的情况，记录未售完库存的种类并退出
    }

    if (ver != -1) // ver不等于-1说明ver被赋过值，也就是有未清空库存的情况。
        rest = (target-sale[0]) * price[ver][1] / price[ver][0]; // 计算部分售价 

    printf("%.2f", sale[1] + rest);

    return 0;
}
