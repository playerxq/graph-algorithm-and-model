// uva-10986-send msg-bellman ford.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 20010
#define MAXM 100010
#define INF 1000000000
int N, M, S, T, q[MAXD], inq[MAXD];
int first[MAXD], next[MAXM], v[MAXM], w[MAXM], d[MAXD], e;
void add(int a, int b, int c)
{
	w[e] = c;
	v[e] = b;
	next[e] = first[a];
	first[a] = e;
	e++;
}
void init()
{
	int i, j, a, b, c;
    scanf("%d%d%d%d", &N, &M, &S, &T);
    memset(first, -1, sizeof(first));
    e = 0;
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
        add(b, a, c);
    }
}
void SPFA()
{
	int i,j,front,rear,u;
	front = rear = 0;
	for(int i = 0;i<N;i++)
		d[i] = INF;
	d[S] = 0;
	q[rear++] = S;
	while(front!=rear)
	{
		u = q[front++];
		if(front>N)
			front = 0;
		inq[u] = 0;
		for(j = first[u];j!=-1;j=next[j])
		{
			if(d[u]+w[j]<d[v[j]])
			{
				d[v[j]] = d[u] + w[j];
				if(inq[v[j]]==0)
				{
					q[rear++] = v[j];
					if(rear>N)
						rear = 0;
					inq[v[j]] = 1;
				}
			}
		}
	}
	if(d[T] == INF)
        printf("unreachable\n");
    else
        printf("%d\n", d[T]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, tt;
    scanf("%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        init();
        printf("Case #%d: ", tt + 1);
        SPFA();
    }
    return 0;
}

