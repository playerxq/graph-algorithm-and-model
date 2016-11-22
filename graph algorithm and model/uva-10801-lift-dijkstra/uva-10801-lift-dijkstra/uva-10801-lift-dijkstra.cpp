// uva-10801-lift-dijkstra.cpp : �������̨Ӧ�ó������ڵ㡣
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
const int MAXN = 105, INF = 1000000;  
int speed[MAXN], floors[MAXN];  
int w[MAXN][MAXN], d[MAXN];  
int n, k, num;  
bool vis[MAXN];  
void build_G(int ss)//��������ͼ  
{  
    for(int i=0; i<num; i++)  
        for(int j=i+1; j<num; j++)  
        {  
            int dis = abs(floors[i]-floors[j]) * speed[ss];  
            if(dis < w[floors[i]][floors[j]])  
                w[floors[i]][floors[j]] = w[floors[j]][floors[i]] = dis;  
        }  
}
void dijkstra()
{
	for(int i = 0; i < 100; i++)  
        d[i] = (i == 0) ? 0 : INF; 
	memset(vis, false, sizeof(vis)); 
	for(int i = 0;i<100;i++)
	{
		int x, m = INF;
		for(int j = 0;j<100;j++)//�ҵ�����d[j]
		{
			if(!vis[j]&&d[j]<m)
			{
				m = d[x=j];
			}
		}
		vis[x] = 1;
		for(int y = 0; y < 100; y++)  
            if(d[y] > d[x] + w[x][y] + 60)//ÿ�����˶�����ȴ�60s  
                d[y] = d[x] + w[x][y] + 60; 
	}
	if(d[k] == INF)  
        printf("IMPOSSIBLE\n");  
    else  
    {  
        if(k == 0)  
            puts("0");  
        else printf("%d\n", d[k]-60);//��ȥ��ʼ�����60s  
    }
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    while(scanf("%d%d", &n, &k) != EOF)  
    {  
        memset(w, INF, sizeof(w));  
        for(int i=0; i<n; i++)  
            scanf("%d", &speed[i]);  
        for(int i=0; i<n; i++)  
        {  
            num = 0;  
            while(1)  
            {  
                scanf("%d", &floors[num++]);  
                if(getchar() == '\n')  
                    break;  
            }  
            build_G(i);  
        }  
        dijkstra();  
    }  
    return 0; 
}

