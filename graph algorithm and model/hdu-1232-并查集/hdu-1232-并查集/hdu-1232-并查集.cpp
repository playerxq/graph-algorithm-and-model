// hdu-1232-并查集.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int p[1001],dep[1001],vis[1001];
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
void union_set(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b)
		return;
	if(dep[a]>dep[b])
		p[b]=a;
	else
	{
		if(dep[a]==dep[b])
			dep[b]++;
		p[a]=b;
	}
	return;
}
void init()
{
	for(int i = 0;i<1001;i++)
	{
		p[i]=i;
		dep[i]=0;
		vis[i]=0;
	}
}
int N,M,a,b;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&N)!=EOF)
	{
		if(!N)
			break;
		init();
		scanf("%d",&M);
		for(int i = 0;i<M;i++)
		{
			scanf("%d %d",&a,&b);
			union_set(a,b);
			vis[a]=vis[b]=1;
		}
		int count = 0;
		for(int i = 1;i<=N;i++)
		{
			if(vis[i]&&(p[i]==i))
				count++;
			else if(!vis[i])
				count++;
		}
		printf("%d\n",count-1);
	}
}

