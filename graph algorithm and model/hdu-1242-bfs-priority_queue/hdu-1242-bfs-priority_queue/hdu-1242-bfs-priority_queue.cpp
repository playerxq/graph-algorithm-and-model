// hdu-1242-bfs-priority_queue.cpp : 定义控制台应用程序的入口点。
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
struct Node
{
	int x,y,step;
	friend bool operator < (struct Node a, struct Node b)
	{
		return b.step<a.step;
	}
} node;
int n,m,vis[205][205];
char map[205][205];
int x_1,x2,y_1,y2;  
int to[4][2] = {1,0,-1,0,0,1,0,-1};  
int check(int x,int y)  
{  
    if(x<0 || y<0 || x>=n || y>=m || !vis[x][y] || map[x][y] == '#')  
        return 1;  
    return 0;  
} 
int bfs()
{
	priority_queue<struct Node> Q;
	struct Node a,next;
	a.x = x_1;
	a.y = y_1;
	a.step = 0;
	Q.push(a);
	vis[x_1][y_1] = 0;
	while(!Q.empty())
	{
		a = Q.top();
		Q.pop();
		if(a.x == x2 && a.y == y2)  
            return a.step; 
		for(int i = 0; i<4; i++)  
        {  
            next = a;  
            next.x+=to[i][0];  
            next.y+=to[i][1];  
            if(check(next.x,next.y))//判断  
                continue;  
            next.step++;  
            if(map[next.x][next.y] == 'x')//卫兵处多花费了一秒  
                next.step++;  
            if(vis[next.x][next.y]>=next.step)//存入最小时间  
            {  
                vis[next.x][next.y] = next.step;  
                Q.push(next);  
            }  
        }
	}
	return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i,j;  
    while(~scanf("%d%d",&n,&m))  
    {  
        for(i = 0; i<n; i++)  
        {  
            scanf("%s",map[i]);  
            for(j = 0; map[i][j]; j++)  
            {  
                if(map[i][j] == 'r')  
                {  
                    x_1 = i;  
                    y_1 = j;  
                }  
                else if(map[i][j] == 'a')  
                {  
                    x2 = i;  
                    y2 = j;  
                }  
            }  
        }  
        memset(vis,1,sizeof(vis));  
        int ans = 0;  
        ans = bfs();  
        if(ans)  
            printf("%d\n",ans);  
        else  
            printf("Poor ANGEL has to stay in the prison all his life.\n");  
    }  
  
    return 0; 
}

