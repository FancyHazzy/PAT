int main(void)  
{  
    static int a[10000];  
    int n,i,b;  
    scanf("%d",&n);  
    for (i=1;i<=n;i++)  
    {  
        scanf("%d",&b);  
        if (i>b)  
        {  
            b=i-b;  
        }  
        else  
        {  
            b-=i;  
        }  
        a[b]++;  
    }  
    for (;n>=0;n--)  
    {  
        if (a[n]>1)  
        {  
            printf("%d %d\n",n,a[n]);  
        }  
    }  
    return 0;  
}  
