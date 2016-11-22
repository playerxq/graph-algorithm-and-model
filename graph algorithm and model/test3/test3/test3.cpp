// test3.cpp : 定义控制台应用程序的入口点。
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
int a[5];
int c[10];
int sum;
void back_track(int cur, int i)
{
	if(cur==5)
	{
		sum++;
		for(int k = 0;k<4;k++)
			printf("%d ",a[k]);
		printf("%d\n",a[4]);
		return;
	}
	int sss = 0;
	for(int k = i;k<=9;k++)//剩余球数
		sss+=c[k];
	if(sss<5-cur)//剪枝
		return;
	for(int k = i;k<=9;k++)
	{
		if(c[k])
		{
			c[k]--;
			a[cur] = k;
			back_track(cur+1,k);
			c[k]++;
		}
	}
	return;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	sum = 0;
	for(int i = 0;i<=9;i++)
		scanf("%d",&c[i]);
	back_track(0,0);
	printf("%d\n",sum);
	return 0;
}

