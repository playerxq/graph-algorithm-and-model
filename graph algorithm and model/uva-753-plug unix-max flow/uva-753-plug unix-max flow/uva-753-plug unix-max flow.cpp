// uva-753-plug unix-max flow.cpp : 定义控制台应用程序的入口点。
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
#define INF 0x3f3f3f3f
#define N 1005
int a[1005],p[1005],flow[1005][1005],cap[1005][1005];
int rec[N];
int f,s,t,tmp;
int n, m, k;
queue<int> Q;
char name[N][N];  
  
int find(char *ch) {  
    for (int i = 0; i < tmp; i++) {  
        if (strcmp(ch, name[i]) == 0) return i;  
    }  
  
    strcpy(name[tmp], ch);  
    return tmp++;  
}
void init() {  
  
    tmp = 1;  
    memset(cap, 0, sizeof(cap));  
    memset(flow, 0, sizeof(flow));  
    memset(name, 0, sizeof(name));  
  
    char ch[N], na[N];  
  
    scanf("%d", &n);  //n个插座
	s = 0;
    for (int i = 0; i < n; i++) {  
  
        scanf("%s", ch);  
        int p = find(ch);  
        cap[0][p]++;  
    }  
  
    scanf("%d", &m);  //电器
    for (int i = 0; i < m; i++) {  
  
        scanf("%s%s", na, ch);  
        int p = find(ch);  
        rec[i] = p;  //电器对应的插座
    }  
  
    scanf("%d", &k);  //适配器
    for (int i = 0; i < k; i++) {  
  
        scanf("%s%s", ch, na);  //两种插座可以转接  建立边
        int p = find(ch), q= find(na);  
        cap[q][p] = INF;  //适配器无数  故容量INF
    }  
	for (int i = 0; i < m; i++)  //电器对应的插座与终点连接
        cap[rec[i]][tmp]++; 
}
int max_flow()
{
	f = 0;
	t = tmp;
	memset(flow,0,sizeof(f));
	for(;;)
	{
		memset(a,0,sizeof(a));
		a[s] = INF;
		Q.push(s);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int i = 0;i<=t;i++)
			{
				if(!a[i]&&cap[u][i]>flow[u][i])
				{
					p[i] = u;
					Q.push(i);
					a[i] = min(a[u],cap[u][i]-flow[u][i]);
				}
			}
		}
		if(a[t]==0) break;
		for(int i = t;i!=s;i=p[i])
		{
			flow[p[i]][i] += a[t];
			flow[i][p[i]] -= a[t];
		}
		f+=a[t];
	}
	return m-f;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cas;  
    scanf("%d", &cas);  
    while (cas--) {  
  
        init();  
        printf("%d\n", max_flow());  
  
        if (cas) printf("\n");  
    }  
    return 0; 
}

