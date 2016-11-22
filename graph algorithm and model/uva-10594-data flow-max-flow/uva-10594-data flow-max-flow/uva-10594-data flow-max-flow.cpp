// uva-10594-data flow-max-flow.cpp : 定义控制台应用程序的入口点。
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
#include <climits>  
#include <algorithm>
#include<utility>  
using namespace std;
#define MAXD 110
#define MAXM 20100
const long long int INF = 10000000000000000ll;
long long d[MAXD];
queue<int> Q;
int s,t;
long long a1,f,c;
long long int w[MAXM], cost[MAXM], cap[MAXM],flow[MAXM], D, K;
int p[MAXD], link[MAXD], q[MAXD], inq[MAXD];
int first[MAXD], next[MAXM], v[MAXM], a[MAXM], b[MAXM], N, M, e;
void add(int x, int y, long long int c, long long int f)
{
	v[e] = y;
	next[e] = first[x];
	first[x] = e;
	cost[e] = c;
	cap[e] = f;
	e++;
}
int init()
{
    int i;
    if(scanf("%d%d", &N, &M) != 2)
        return 0;
    for(i = 0; i < M; i ++)
        scanf("%d%d%lld", &a[i], &b[i], &w[i]);
    scanf("%lld%lld", &D, &K);
    e = 0;
    memset(first, -1, sizeof(first));
    for(i = 0; i < M; i ++)
    {
        add(a[i], b[i], w[i], K);
        add(b[i], a[i], -w[i], 0);
        add(b[i], a[i], w[i], K);
        add(a[i], b[i], -w[i], 0);
    }
    add(0, 1, 0, D);
    add(1, 0, 0, 0);
    return 1;
}
long long max_flow()
{
	s = 0;
	f = 0;
	c = 0;
	t = N;
	memset(flow,0,sizeof(flow));
	for(;;)
	{
		for(int i = 0;i<MAXD;i++)
			d[i] = INF;
		d[s] = 0;
		memset(inq,0,sizeof(inq));
		Q.push(s);
		inq[s] = 1;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			for(int i = first[u];i!=-1;i = next[i])
			{
				if(cap[i]>flow[i]&&d[v[i]]>d[u]+cost[i])
				{
					d[v[i]]=d[u]+cost[i];
					p[v[i]] = u;
					link[v[i]] = i;//终点为v[i]的边
					if(inq[v[i]]==0)
					{
						inq[v[i]] = 1;
						Q.push(v[i]);
					}
				}
			}
		}
		if(d[t]==INF)
			break;
		a1 = INF;
		for(int u = t;u!=s;u = p[u])
		{
			int y = link[u];
			a1 = min(a1,cap[y]-flow[y]);
		}
		for(int u = t; u != s; u = p[u])
        {
            int y = link[u];
            flow[y] += a1;
            flow[y ^ 1] -= a1;
        }
        c += a1 * d[N];
        f += a1;
	}
	if(f == D)
        return c;
    else
        return -1;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(init())
    {
        long long int res = max_flow();
        if(res >= 0)
            printf("%lld\n", res);
        else
            printf("Impossible.\n");
    }
    return 0;
}

