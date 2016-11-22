// uva-515-king-bellmon-ford-���Լ��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	for(int i = 1;i<=n+1;i++)//���·���ྭ��n+1���� �������0
	{
		for(int j = 0;j<=(m+n);j++)//���ÿ����
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
        for(int i = 0; i < m; i++){  //ÿ����������
            scanf("%d %d %s %d", &b, &e, s, &k);  //��������xj-xi<=bk��(xi,xj)=bk
            if(s[0] == 'g'){  //ǰb+e+1���� - b����  
                u[i] = b + e + 1;  
                v[i] = b;  
                w[i] = -k - 1;  
            }else {  
                u[i] = b;  
                v[i] = b + e + 1;  
                w[i] = k - 1;  
            }  
        }  
        for(int i = 1, j = m; i <= n + 1; j++, i++){  //������0 ���Ӹ�����1:n+1
            u[j] = 0;  
            v[j] = i;  
            w[j] = 0;  
        }  
        if(bellman_ford()) printf("lamentable kingdom\n"); else printf("successful conspiracy\n");  
    }
	return 0;
}

