// uva-125-numbering-path-floyd.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 110
int M, N, f[MAXD][MAXD];
void init()
{
	int i, j, a, b;
    N = 0;
    memset(f, 0, sizeof(f));
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d", &a, &b);
        f[a][b] = 1;
        if(a > N)
            N = a;
        if(b > N)
            N = b;
    }
}
void floyd()
{
	int i,j,k;
	for(k = 0;k<=N;k++)
	{
		for(i = 0;i<=N;i++)
		{
			for(j = 0;j<=N;j++)
			{
				if(f[i][k]&&f[k][j])
					f[i][j] += f[i][k]*f[k][j];
			}
		}
	}
	for(k = 0; k <= N; k ++)
        if(f[k][k])//k处于环路上
        {
            for(i = 0; i <= N; i ++)
                for(j = 0; j <= N; j ++)
                    if(f[i][k] && f[k][j])
                        f[i][j] = -1;
        }
	 for(i = 0; i <= N; i ++)
    {
        for(j = 0; j <= N; j ++)
        {
            if(j)
                printf(" ");
            printf("%d", f[i][j]);
        }
        printf("\n");
    }
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
    while(scanf("%d", &M) == 1)
    {
        init();
        printf("matrix for city %d\n", t ++);
        floyd();
    }
    return 0;
}

