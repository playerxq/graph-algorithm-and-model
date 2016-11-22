// uva-10985-ring rope-floyd.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 150
#define INF 100000000
int f[MAXD][MAXD], M, N, res, ans[MAXD];
void init()
{
    int i, j, a, b;
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
        {
            if(i == j)
                f[i][j] = 0;
            else
                f[i][j] = INF;
        }
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d", &a, &b);
        f[a][b] = f[b][a] = 1;
    }
}
void floyd()
{
    int i, j, k;
    for(k = 0; k < N; k ++)
        for(i = 0; i < N; i ++)
            for(j = 0; j < N; j ++)
                if(f[i][k] + f[k][j] < f[i][j])
                    f[i][j] = f[i][k] + f[k][j];
}
void printresult()
{
    int i, j, k, max = 0;
    for(i = 0; i < N; i ++)
        for(j = i + 1; j < N; j ++)//枚举两个点
            if(f[i][j] != INF)//存在最短路
            {
                res = 0;
                for(k = 0; k < N; k ++)//对所有可能的中间点
                    if(f[i][k] + f[k][j] == f[i][j])
                        ans[res ++] = k;//处于最短路上
                int p, q, temp = 0;
                for(p = 0; p < res; p ++)
                    for(q = p + 1; q < res; q ++)//枚举i:j的中间的点a,b
                    {
                        int a = ans[p];
                        int b = ans[q];
                        if(f[a][b] == 1 && f[i][a] != f[i][b])//a b直接相连且与起点长度不一
                            temp ++;
                    }
                if(temp > max)
                    max = temp;
            }
    printf("%d\n", max);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t, tt;
    scanf("%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        init();
        floyd();
        printf("Case #%d: ", tt + 1);
        printresult();
    }
    return 0;
}

