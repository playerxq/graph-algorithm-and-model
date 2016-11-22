// uva-11045-tshirts suit-max flow.cpp : 定义控制台应用程序的入口点。
//源点和各种衣服都连一条有向边，容量为N/6，
//人所对应的衣服和人之间连一条有向边，容量为1，
//人与汇点之间连一条有向边，容量为1，
//如果最后汇点的流量为M，则表示可以，否则就不可以。

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
#include<utility>  
using namespace std;
#define INF 0x3f3f3f3f
int flow[110][110],cap[110][110];
int a[110],p[110];
int N,s,t,M,f;
queue<int> Q;
char b[][5]={"\0","XXL","XL","L","M","S","XS"};
char b1[5], b2[5];
void init()
{
    int i, j, k, a1, a2;
    memset(cap, 0, sizeof(cap));
    scanf("%d%d", &N, &M);
    t = M + 7;
    for(i = 1; i <= 6; i ++)
        cap[0][i] = N / 6;
	s = 0;
    for(i = 1; i <= M; i ++)
    {
        scanf("%s%s", b1, b2);
        for(a1 = 1; strcmp(b[a1], b1) != 0; a1 ++);
        for(a2 = 1; strcmp(b[a2], b2) != 0; a2 ++);
        cap[a1][i + 6] = 1;
        cap[a2][i + 6] = 1;
        cap[i + 6][t] = 1;
    }
}
int max_flow()
{
	f = 0;
	memset(flow,0,sizeof(flow));
	for(;;)
	{
		memset(a,0,sizeof(a));
		a[s] = INF;
		Q.push(s);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int v = 0;v<=t;v++)
			{
				if(!a[v]&&cap[u][v]>flow[u][v])
				{
					p[v] = u;
					Q.push(v);
					a[v] = min(a[u],cap[u][v]-flow[u][v]);
				}
			}
		}
		if(a[t]==0) break;
		for(int i =  t;i!=s;i = p[i])
		{
			flow[p[i]][i]+=a[t];
			flow[i][p[i]]-=a[t];
		}
		f+=a[t];
	}
	if(f==M)
		return 1;
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i, j, k, t;
    scanf("%d", &t);
    while(t --)
    {
        init();
        if(max_flow())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;  
}

