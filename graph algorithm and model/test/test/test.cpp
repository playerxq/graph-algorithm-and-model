// test.cpp : 定义控制台应用程序的入口点。
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
int d[11][6];//d[i][j]为i-9号球抽取j个  d[i][j] = d[i][j-1]+d[i+1][j]  d[9][j] = 1 d[i][0] = 1
int vis[11][6];
int a[6];
int dp(int i, int j)
{
	if(vis[i][j])
		return d[i][j];
	vis[i][j] = 1;
	if(i==9)
		return d[i][j] = 1;
	if(j==0)
		return d[i][j] = 1;
	d[i][j] += dp(i,j-1)+dp(i+1,j);
	return d[i][j];
}
void print_ans(int i, int j)
{
	if(j==5)
	{
		for(int k = 0;k<4;k++)
			printf("%d ",a[k]);
		printf("%d\n",a[4]);
		return;
	}
	for(int k = i;k<=9;k++)
	{
		a[j] = k;
		print_ans(k,j+1);
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ans = 0;
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	ans = dp(0,5);//总数目
	printf("%d\n",ans);
	print_ans(0,0);//回朔打印
	return 0;
}

