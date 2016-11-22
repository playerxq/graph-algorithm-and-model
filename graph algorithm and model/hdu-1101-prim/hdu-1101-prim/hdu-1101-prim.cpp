// hdu-1101-prim.cpp : 定义控制台应用程序的入口点。
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
#define MAX 105

#define maxx 999999999

int map[MAX][MAX],used[MAX],f[MAX];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int n,i,j,k,m,a,b,minx,sum;
	while(scanf("%d",&n)!=EOF)
	{
		memset(map,0x3f,sizeof(map)); 
		memset(used,0,sizeof(used));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		scanf("%d",&m);
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&a,&b);
			map[a][b]=map[b][a]=0;
		}
		for(i=1;i<=n;i++)
		{
			f[i]=map[1][i];
		}
		for(int i=1;i<=n;i++)  
			f[i]=maxx; 
		f[1]=0;sum=0;
		for(i=1;i<=n;i++)
		{
			minx=maxx;
			for(j=1;j<=n;j++)
			{
				if(!used[j]&&f[j]<minx)
				{
					minx=f[j];k=j;
				}
			}
			used[k]=1;sum+=f[k];
			for(j=1;j<=n;j++)
			{
				if(!used[j]&&f[j]>map[k][j])
				{
					f[j]=map[k][j];
				}
			}
		}
		printf("%d\n",sum);
	}
}

