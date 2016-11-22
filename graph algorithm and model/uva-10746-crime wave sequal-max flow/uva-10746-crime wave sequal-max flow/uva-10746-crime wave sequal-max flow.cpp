// uva-10746-crime wave sequal-max flow.cpp : �������̨Ӧ�ó������ڵ㡣
//m������ϵ� n �����У���֪����ʱ�䣬�Լ�m>=n����ƽ��ʱ�����
//s�뾯���� ����1����0 ������t�� ����1����0 ���������������

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
const int N = 205;
int T = 100;
queue<int> Q;
int inq[N];
double d[N];
double w[N][N];
int flow[N][N];
int cap[N][N];
int p[N];
int s,t,f,a,tmp,n,m;
double c;
vector<int> ve[N];
void add(int x,  int y) {  
    cap[x][y]++;  
    ve[x].push_back(y);  
    ve[y].push_back(x);  
}
void init()
{
	tmp = 200;  
    memset(cap, 0, sizeof(cap));  
    memset(flow, 0, sizeof(flow));  
    memset(w, 0, sizeof(w)); 
	for (int i = 0; i < N; i++)  
        ve[i].clear(); 
	for (int i = 1; i <= n; i++) {  //n������ ���n����
  
        add(0, i + T);  //i���Ϊ i+T->i
        add(i + T, i); 
		//m�����쵽��n������  �����
        for (int j = 1; j <= m; j++) {  //����1:m��1��n�ظ� 1:m����ӳ��Ϊ1+n:n+m��
            add(i, j + n + T);  
        }  
    }  
  
    for (int i = 1; i <= m; i++) {  //�Ƚ�iӳ�䵽i+n  i+n��Ϊi+n+T->i+n
        add(i + n + T, i + n);  
        add(i + n, tmp);  
    }  
  //m�����쵽��n�����е�ʱ��  ��ΪȨֵ
    for (int i = 1; i <= n; i++) {  
        for (int j = 1; j <= m; j++) {  
            scanf("%lf", &w[i][j + n + T]);  
            w[j + n + T][i] = -w[i][j + n + T];  
        }  
    } 
}
void max_flow()
{
	memset(flow,0,sizeof(flow));
	s=0;
	t=tmp;
	c = f= 0;
	for(;;)
	{
		for(int i = 1;i<=N;i++)//bellman ford������
				d[i] = INF;
		memset(inq,0,sizeof(inq));
		d[s] = 0;
		Q.push(s);
		inq[s] = 1;
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			for(int v = 0;v<ve[u].size();v++)
			{
				if(cap[u][ve[u][v]]>flow[u][ve[u][v]]&&d[ve[u][v]]-d[u]-w[u][ve[u][v]]>1e-6)
				{
					p[ve[u][v]] = u;
					d[ve[u][v]] = d[u]+w[u][ve[u][v]];
					if(inq[ve[u][v]]==0)
					{
						inq[ve[u][v]] = 1;
						Q.push(ve[u][v]);
					}
				}
			}
		}
		if(INF-d[t]<1e-6) break;
		a = INF;
		for(int i = t;i!=s;i=p[i])
			a = min(a,cap[p[i]][i]-flow[p[i]][i]);
		for(int i = t;i!=s;i=p[i])
		{
			flow[p[i]][i]+=a;
			flow[i][p[i]]-=a;
		}
		f+=a;
		c+=d[t]*a;
	}
	printf("%.2lf\n", c / n + 0.001); 
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (scanf("%d%d", &n, &m), n + m) {  
        init();  
        max_flow();  
    } 
	return 0;
}

