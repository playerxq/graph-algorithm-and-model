// uva-558-wormhole-bellmon ford.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 1010
#define MAXM 2010
#define INF 1000000000
int d[MAXD], q[MAXD], inq[MAXD], inedq[MAXD];
int N, M, first[MAXD], e, next[MAXM], v[MAXM], w[MAXM];
void add(int a, int b, int c)
{
    v[e] = b;
    w[e] = c;
    next[e] = first[a];
    first[a] = e;
    e ++;
}
void init()
{
    int i, a, b, c;
    scanf("%d%d", &N, &M);
    memset(first, -1, sizeof(first));
    e = 0;
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
}
int SPFA()//某点入队次数大于N  存在负权回路
{
	int i, u, front, rear;
    front = rear = 0;
    for(i = 0; i < N; i ++)
        d[i] = INF;
    d[0] = 0;
    memset(inq, 0, sizeof(inq));
    memset(inedq, 0, sizeof(inedq));
    q[rear ++] = 0;
	while(front!=rear)
	{
		u = q[front++];
		if(front>N)
			front = 0;
		inq[u] = 0;
		for(i = first[u];i!=-1;i = next[i])
		{
			if(d[u]+w[i]<d[v[i]])
			{
				d[v[i]] = d[u]+w[i];
				if(inq[v[i]]==0)
				{
					q[rear++] = v[i];
					if(rear>N)
						rear = 0;
					inq[v[i]] = 1;
					if(inedq[v[i]]++>N)
						return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
    scanf("%d", &t);
    while(t --)
    {
        init();
        if(SPFA())
            printf("possible\n");
        else
            printf("not possible\n");
    }
    return 0;
}

