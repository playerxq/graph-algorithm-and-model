// uva-10330-power-transmission-max_flow.cpp : 定义控制台应用程序的入口点。
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

const int Maxn = 260;
const int inf = 99999999;
int n, m, cap[Maxn], B, D, S, E, map[Maxn][Maxn], flow[Maxn][Maxn];
int a[Maxn], p[Maxn];

int maxFlow() {
    memset(flow,0,sizeof(flow));
	queue<int> Q;
	int f = 0;
	while(1)
	{
		memset(a,0,sizeof(a));
		a[S] = inf;
		Q.push(S);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int v = 0;v<=2*n+1;v++)
			{
				if(!a[v]&&map[u][v]>flow[u][v])
				{
					p[v] = u;
					Q.push(v);
					a[v] = min(a[u],map[u][v]-flow[u][v]);
				}
			}
		}
		if(a[E]==0) break;
		for(int i = E;i!=S;i=p[i])
		{
			flow[p[i]][i]+=a[E];
			flow[i][p[i]]-=a[E];
		}
		f+=a[E];
	}
	return f;
}

void buildMap() {//i点拆为i:i+n
    for ( int i = 0; i < m; ++i ) {
        int si, ei, ci;
        scanf("%d%d%d", &si, &ei, &ci);
        map[si + n][ei] += ci;
    }
    scanf("%d%d", &B, &D);
    for ( int i = 0; i < B; ++i ) {
        int ei;
        scanf("%d", &ei);
        map[0][ei] = inf;
    }
    for ( int i = 0; i < D; ++i ) {
        int si;
        scanf("%d", &si);
        map[si+n][E] = inf;
    }
    for ( int i = 1; i <= n; ++i ) map[i][i+n] += cap[i];
}   

int main() {
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    while ( scanf("%d", &n ) != EOF ) {
        for ( int i = 1; i <= n; ++i ) scanf("%d", cap + i);//点容量
        scanf("%d", &m);
        memset( map, 0, sizeof(map) );
        S = 0, E = n + n + 1;//拆分后为2n个点
        buildMap();
        printf("%d\n", maxFlow());
    }
}

