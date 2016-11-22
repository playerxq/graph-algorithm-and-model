// hdu-1241-dfs.cpp : 定义控制台应用程序的入口点。
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
int n,m;
char mp[105][105];
int vis[105][105];
int dir[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
int cnt;
int ok(int x, int y)
{
	return ((x>=0)&&(x<n)&&(y>=0)&&(y<m));
}
void dfs(int x, int y)
{
	if(vis[x][y])
		return;
	vis[x][y]=1;
	for(int i = 0;i<8;i++)
	{
		int nx = x+dir[i][0];
		int ny = y+dir[i][1];
		if(ok(nx,ny))
			dfs(nx,ny);
	}
	return;
}
int calc()
{
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			if(!vis[i][j])
			{
				cnt++;
				dfs(i,j);
			}
		}
	}
	return cnt;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n+m==0)
			break;
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<n;i++)
			scanf("%s",mp[i]);
		for(int i = 0;i<n;i++)
		{
			for(int j = 0;j<m;j++)
			{
				if(mp[i][j]=='*')
					vis[i][j] = 1;
			}
		}
		cnt = 0;
		printf("%d\n",calc());
	}
}

