// uva-10273-eat or not-enumeration.cpp : 定义控制台应用程序的入口点。
//n头牛，每头有产奶周期，现在要杀牛，如果当天能找到产奶最小的牛且只数为1，就可杀
//问最后剩几头牛和最后杀牛的天数。

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
#define MAXD 1010
#define INF 1000000000
int N, T, t[MAXD], d[MAXD][20], U[MAXD], D[MAXD], st[MAXD];//u[i] d[i]为i的上下索引 链表
//st[i]为第i头牛考虑到第几天 即总天数对每个牛的产奶周期的模  每个牛单独计算

int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}
void init()
{
    int i, j, k;
    scanf("%d", &N);
    for(i = 1; i <= N; i ++)
    {
        scanf("%d", &t[i]);
        for(j = 0; j < t[i]; j ++)//第i头牛第j天产奶量
            scanf("%d", &d[i][j]);
    }
    for(i = 0; i <= N; i ++)//初始化链表
    {
        D[i] = i + 1;
        U[i + 1] = i;
    }
    D[N] = 0;//循环表
    memset(st, 0, sizeof(st));
    T = 1;
    for(i = 1; i <= N; i ++)
    {
        if(T < t[i])
            k = gcd(t[i], T);
        else
            k = gcd(T, t[i]);
        T = T * t[i] / k;//lcm  总周期
    }
}
void solve()
{
    int i, j, k, cur, min, num, flag, a, p, sum;
    num = min = 0;
    for(p = 0;;p++)//已经过的周期
	{
		flag =0;
		for(cur = 1;cur<=T;cur++)//查看一个周期内杀牛数以及最后杀牛天数
		{
			a = INF;
			for(i = D[0];i!=0;i = D[i])
			{
				if(d[i][st[i]]<a)//找到当天产奶最小的牛
				{
					a = d[i][st[i]];
					k = i;
					sum = 1;
				}
				else if(d[i][st[i]]==a)
					sum++;
				st[i] = (st[i]+1)%t[i];//每个牛单独过一天
			}
			if(sum==1)
			{
				flag = 1;
				U[D[k]] = U[k];
				D[U[k]] = D[k];
				min = p*T+cur;//最后杀牛天数
				num++;
			}
		}
		if(!flag)//当前一个T周期内没有牛被杀 稳定
			break;
	}
    printf("%d %d\n", N - num, min);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
    scanf("%d", &test);
    while(test --)
    {
        init();
        solve();
    }
    return 0;
}

