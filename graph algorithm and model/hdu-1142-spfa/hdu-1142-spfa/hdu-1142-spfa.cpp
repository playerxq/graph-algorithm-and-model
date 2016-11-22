// hdu-1142-spfa.cpp : 定义控制台应用程序的入口点。
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
queue<int> Q;
const int INF = 99999999; 
int inq[1005];
int n, t, sum; 
vector<int> road[1005]; 
int map[1005][1005], d[1005], s[1005];
void init()  
{  
    int i, j;  
    sum = 0;  
    memset(s, 0, sizeof(s));  
    for(i = 0; i <= n; i++) road[i].clear();  
    for(i = 0; i <= n; i++)  
        for(j = 0; j <= n; j++)  
            if(i == j) map[i][j] = 0;  
            else map[i][j] = INF;  
}
void input()  
{  
    int a, b, d;  
    while(t--)  
    {  
        scanf("%d %d %d", &a, &b, &d);  
        if(d < map[a][b])  
        {  
            map[a][b] = map[b][a] = d;  //双向的  
            road[a].push_back(b);  
            road[b].push_back(a);  
        }  
    }  
} 
void spfa()
{
	memset(inq,0,sizeof(inq));
	int i, now;
	for(i = 1;i<=n;i++)
		d[i]=INF;
	d[2]=0;
	Q.push(2);
	inq[2]=1;
	while(!Q.empty())
	{
		now = Q.front();
		Q.pop();
		inq[now] = 0;
		for(i = 1;i<=n;i++)
		{
			if(d[i]>d[now]+map[now][i])
			{
				d[i] = d[now]+map[now][i];
				if(inq[i]==0)
				{
					inq[i]=1;
					Q.push(i);
				}
			}
		}
	}

}
int dfs(int cur)
{
	if(cur==2)
		return 1;
	if(s[cur])
		return s[cur];
	for(int i = 0;i<road[cur].size();i++)
	{
		if(d[cur]>d[road[cur][i]])
			s[cur]+=dfs(road[cur][i]);
	}
	return s[cur];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d", &n), n)  
    {  
        scanf("%d", &t);  
        init();  
        input();  
        spfa();  
        sum = dfs(1);   //sum一共多少条路，sum = s[1] 也行  
        printf("%d\n", sum);  
    } 
}

