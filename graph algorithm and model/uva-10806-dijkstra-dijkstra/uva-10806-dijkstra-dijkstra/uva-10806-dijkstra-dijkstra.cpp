// uva-10806-dijkstra-dijkstra.cpp : 定义控制台应用程序的入口点。
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
const int MAXN = 100+5, INF = 0x3f3f3f3f;
int n, m, w[MAXN][MAXN];
int s, t, c, f, d[MAXN], p[MAXN], flow[MAXN][MAXN], cap[MAXN][MAXN];
bool inq[MAXN];
queue<int> Q;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(!n) break;
		scanf("%d",&m);
		memset(w, 0x3f, sizeof(w));
        memset(cap, 0, sizeof(cap));
		for (int i = 1; i <= m; i++)
        {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            w[x][y] = w[y][x] = z;
            cap[x][y] = cap[y][x] = 1;
        }
		s = n+1; cap[s][1] = 2; w[s][1] = w[1][s] = 0;//增加源点与终点  容量2
        t = n+2; cap[n][t] = 2; w[n][t] = w[t][n] = 0;
		int N = n+2;
        memset(flow, 0, sizeof(flow));
        c = f = 0;
		for(;;)//最小费用最大流
		{
			for(int i = 1;i<=N;i++)//bellmon ford找增广
				d[i] = INF;
			memset(inq,0,sizeof(inq));
			d[s] = 0;
			Q.push(s);
			while(!Q.empty())
			{
				int u = Q.front();
				Q.pop();
				inq[u] = 0;
				for(int i = 1;i<=N;i++)
				{
					if(cap[u][i]>flow[u][i]&&d[i]>d[u]+w[u][i])
					{
						d[i]=d[u]+w[u][i];
						p[i] = u;
						if(inq[i]==0)
						{
							Q.push(i);
							inq[i] = 1;
						}
					}
				}
			}
			if(d[t]==INF) break;
			int a = INF;
			for (int v = t; v != s; v = p[v])
            {
                a = min(a, cap[p[v]][v]-flow[p[v]][v]);
                w[p[v]][v] = w[v][p[v]] = -w[p[v]][v];
            }
			for(int i = t;i!=s;i=p[i])
			{
				flow[p[i]][i] += a;
				flow[i][p[i]] -= a;
			}
			c+=d[t]*a;
			f+=a;
		}
		if (f < 2)
            printf("Back to jail\n");
        else
            printf("%d\n", c);
	}
	return 0;
}

