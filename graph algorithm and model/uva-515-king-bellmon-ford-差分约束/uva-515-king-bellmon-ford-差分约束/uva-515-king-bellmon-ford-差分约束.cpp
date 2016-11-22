// uva-515-king-bellmon-ford-差分约束.cpp : 定义控制台应用程序的入口点。
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
#define MAXN 220  
#define INF (1 << 30)  
int u[MAXN], v[MAXN], w[MAXN], d[MAXN];  
int m, n; 
int bellman_ford()
{
	for(int i = 0;i<=n+1;i++)
		d[i] = INF;
	d[0] = 0;
	for(int i = 1;i<=n+1;i++)//最短路至多经过n+1个点 不算起点0
	{
		for(int j = 0;j<=(m+n);j++)//检查每条边
		{
			if(d[v[j]] > d[u[j]] + w[j])  
                d[v[j]] = d[u[j]] + w[j];
		}
	}
	for(int j = 0; j <= (m + n); j++)  
        if(d[v[j]] > d[u[j]] + w[j])    return 0;  
    return 1;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char s[10];  
    int b, e, k;  
    memset(u, 0, sizeof(u));  
    memset(v, 0, sizeof(v));  
    memset(w, 0, sizeof(w));  
    while(scanf("%d", &n) == 1, n){  
        scanf("%d", &m);  
        for(int i = 0; i < m; i++){  //每个限制条件
            scanf("%d %d %s %d", &b, &e, s, &k);  //限制条件xj-xi<=bk则弧(xi,xj)=bk
            if(s[0] == 'g'){  //前b+e+1个和 - b个和  
                u[i] = b + e + 1;  
                v[i] = b;  
                w[i] = -k - 1;  
            }else {  
                u[i] = b;  
                v[i] = b + e + 1;  
                w[i] = k - 1;  
            }  
        }  
        for(int i = 1, j = m; i <= n + 1; j++, i++){  //超级点0 连接各个点1:n+1
            u[j] = 0;  
            v[j] = i;  
            w[j] = 0;  
        }  
        if(bellman_ford()) printf("lamentable kingdom\n"); else printf("successful conspiracy\n");  
    }
	return 0;
}

