// hdu-1233-最小生成树.cpp : 定义控制台应用程序的入口点。
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
int mp[101][101];
const int maxx = 0x3f3f3f3f;
int f[101];
int used[101];
int N,a,b,c,k;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%d",&N)!=EOF)
	{
		if(!N)
			break;
		memset(mp,0,sizeof(mp));
		memset(f,0,sizeof(f));
		memset(used,0,sizeof(used));
		for(int i = 0;i<N*(N-1)/2;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			mp[a-1][b-1]=mp[b-1][a-1]=c;
		}
		used[0]=1;
		for(int i=1;i<N;i++)
		{
			f[i]=mp[0][i];
		}
		int sum=0;
		for(int i=1;i<N;i++)
		{
			int minx=maxx;
			for(int j=0;j<N;j++)
			{
				if(!used[j]&&f[j]<minx)
				{
					minx=f[j];k=j;
				}
			}
			used[k]=1;sum+=f[k];
			for(int j=0;j<N;j++)
			{
				if(!used[j]&&f[j]>mp[k][j])
				{
					f[j]=mp[k][j];
				}
			}
		}
		printf("%d\n",sum);
	}
}

