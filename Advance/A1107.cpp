//并查集


#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n;
const int maxn=1010;
int father[maxn];
int isRoot[maxn]={0};
int course[maxn]={0};
int findFather(int x);
void Union(int a,int b);
void init();
bool cmp(int a,int b);
int main()
{
	scanf("%d",&n);
	init();
	int h;
	int k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d:",&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&h);//输入第i个人的爱好h 
			if(course[h]==0)//如果活动h第一次有人喜欢 
				course[h]=i;
			Union(i,findFather(course[h]));
			//合并到father，father代表了每个人的社交网络，可以不断回溯到根节点
			//根节点相同的人属于一个网络 
		}
	}
	for(int i=1;i<=n;i++)
		isRoot[findFather(i)]++;//计算每个集合有多少人
	int ans=0;//集合数目 
	for(int i=1;i<=n;i++)
		if(isRoot[i]!=0)
			ans++;
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i=1;i<=ans;i++)
	{
		printf("%d",isRoot[i]);
		if(i<ans)
			printf(" ");
	}
	return 0;
}
 
int findFather(int x)
{
	while(x!=father[x])
		x=father[x];
	return x;
}
 
void Union(int a,int b)
{
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB)
		father[faA]=faB;
}
 
void init()
{
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
		isRoot[i]=false;
	}
}
 
bool cmp(int a,int b)
{
	return a>b;
}
