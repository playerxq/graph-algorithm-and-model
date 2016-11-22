// uva-10985-ring rope-floyd.cpp : �������̨Ӧ�ó������ڵ㡣
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
        for(j = i + 1; j < N; j ++)//ö��������
            if(f[i][j] != INF)//�������·
            {
                res = 0;
                for(k = 0; k < N; k ++)//�����п��ܵ��м��
                    if(f[i][k] + f[k][j] == f[i][j])
                        ans[res ++] = k;//�������·��
                int p, q, temp = 0;
                for(p = 0; p < res; p ++)
                    for(q = p + 1; q < res; q ++)//ö��i:j���м�ĵ�a,b
                    {
                        int a = ans[p];
                        int b = ans[q];
                        if(f[a][b] == 1 && f[i][a] != f[i][b])//a bֱ������������㳤�Ȳ�һ
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

