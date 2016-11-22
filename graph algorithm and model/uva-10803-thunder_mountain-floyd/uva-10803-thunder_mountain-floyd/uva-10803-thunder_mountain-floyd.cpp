// uva-10803-thunder_mountain-floyd.cpp : 定义控制台应用程序的入口点。
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
#define INF 1000000000
int N;
double f[MAXD][MAXD], x[MAXD], y[MAXD];
double sqr(double x)
{
    return x * x;
}
void init()
{
    int i, j;
    scanf("%d", &N);
    for(i = 0; i < N; i ++)
        scanf("%lf%lf", &x[i], &y[i]);
    for(i = 0; i < N; i ++)
        for(j = 0; j < N; j ++)
        {
            if(i == j)
                f[i][j] = 0;
            else
            {
                f[i][j]= sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
                if(f[i][j] > 10.0)
                    f[i][j] = INF;
            }
        }
}
void floyd()
{
    int i, j, k;
    double ans;
    for(k = 0; k < N; k ++)
        for(i = 0; i < N; i ++)
            for(j = 0; j < N; j ++)
                if(f[i][k] + f[k][j] < f[i][j])
                    f[i][j] = f[i][k] + f[k][j];
    ans = 0;
    for(i = 0; i < N; i ++)//找到最长的最优路径
        for(j = 0; j < N; j ++)
            if(f[i][j] > ans)
                ans = f[i][j];
    if(fabs(ans - INF) < 1)
        printf("Send Kurdy\n");
    else
        printf("%.4f\n", ans);
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
        printf("Case #%d:\n", tt + 1);
        floyd();
        printf("\n");
    }
    return 0;
}

