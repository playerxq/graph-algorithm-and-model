// uva-10269-mario-floyd-bellman ford.cpp : �������̨Ӧ�ó������ڵ㡣
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
#define MAXD 130
#define MAXN 20
#define INF 1000000000
int A, B, M, L, K, N;
//G[i][j]Ϊi��j����
//d[i][j]ΪA+B����iʱʹ����j�η�Ծ����̾���  inqΪ��״̬
//Ϊͬʱ����i j  ������������ͬʱ����  q st
int G[MAXD][MAXD], d[MAXD][MAXN], st[MAXD * MAXN];
int q[MAXD * MAXN], inq[MAXD][MAXN];
void init()
{
    int i, j, k, a, b, t;
    scanf("%d%d%d%d%d", &A, &B, &M, &L, &K);
    N = A + B;
    for(i = 1; i <= N; i ++)
        for(j = 1; j <= N; j ++)
        {
            if(i == j)
                G[i][j] = 0;//���
            else
                G[i][j] = INF;
        }
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d%d", &a, &b, &t);
        G[a][b] = G[b][a] = t;
    }
}
void floyd()
{
    int i, j, k;
    for(k = 1; k <= N; k ++)
        for(i = 1; i <= N; i ++)
            for(j = 1; j <= N; j ++)
                if(k <= A && G[i][k] + G[k][j] < G[i][j])//�Ǳ�������Ϊ��ת�㴩Խ  ���Ǳ�����ͣ�½���һ�ξ��� 
                    G[i][j] = G[i][k] + G[k][j];
}
int bellman_ford()
{
	int i, j, k, u, v, front, rear, max = (K + 1) * N;
	front = rear = 0;
	memset(inq,0,sizeof(inq));
	for(i = 1;i<=N;i++)
		for(j = 0;j<=K;j++)
			d[i][j] = INF;
	d[N][0] = 0;
	q[rear] = N;
	st[rear] = 0;
	rear++;
	while(front!=rear)
	{
		u = q[front];
		k = st[front];
		front++;
		inq[u][k] = 0;
		if(front>max)
			front = 0;
		for(v = 1;v<=N;v++)
		{
			if(G[u][v]+d[u][k]<d[v][k])//����Ծ
			{
				d[v][k] = d[u][k]+G[u][v];
				if(!inq[v][k])
				{
					inq[v][k] = 1;
					q[rear] = v;
					st[rear] = k;
					rear++;
					if(rear>max)
						rear = 0;
				}
			}
			if(G[u][v] <= L && k < K && d[u][k] < d[v][k + 1])//��Ծ
            {
                d[v][k + 1] = d[u][k];
                if(!inq[v][k + 1])
                {
                    q[rear] = v;
                    st[rear] = k + 1;
                    rear ++;
                    if(rear > max)
                        rear = 0;
                    inq[v][k + 1] = 1;
                }
            }
		}
	}
	int res = INF;
	for(i = 0;i<=K;i++)
		if(res>d[1][i])
			res = d[1][i];
	return res;
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
        floyd();
        int res = bellman_ford();
        printf("%d\n", res);
    }
    return 0;
}

