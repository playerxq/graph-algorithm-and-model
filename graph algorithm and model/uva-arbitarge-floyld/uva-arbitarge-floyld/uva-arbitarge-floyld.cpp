// uva-arbitarge-floyld.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 30
#define MAXM 10010
int N, path[MAXD][MAXD][MAXD];
double f[MAXD][MAXD][MAXD];//从i到j经k次
void init()
{
	int i, j;
    memset(f, 0, sizeof(f));
    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
            if(i != j)
            {
                scanf("%lf", &f[i][j][1]);
                path[i][j][1] = i;
            }
}
void print_path(int i, int j, int k)
{
	if(k==0)
	{
		printf("%d",i+1);
	}
	else
	{
		print_path(i,path[i][j][k],k-1);
		printf(" %d",j+1);
	}
}
void floyd()
{
	int i, j, k, p;
	for(p = 1;p<N;p++)//p次中转
	{
		for(k = 0;k<N;k++)
		{
			for(i = 0;i<N;i++)
			{
				for(j = 0;j<N;j++)
				{
					if(f[i][k][p]*f[k][j][1]>f[i][j][p+1]+1e-12)
					{
						f[i][j][p + 1] = f[i][k][p] * f[k][j][1];
                        path[i][j][p + 1] = k;
					}
				}
			}
			for(i = 0; i < N; i ++)//当前中转次数下
				if(f[i][i][p + 1] > 1.01)
				{
					print_path(i, i, p + 1);
					printf("\n");
					return ;
				}
		}
	}
	printf("no arbitrage sequence exists\n");
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d", &N) == 1)
    {
        init();
        floyd();
    }
    return 0;
}

