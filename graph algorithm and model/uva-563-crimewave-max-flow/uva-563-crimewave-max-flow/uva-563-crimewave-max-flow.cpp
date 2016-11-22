// uva-563-crimewave-max-flow.cpp : �������̨Ӧ�ó������ڵ㡣
//ÿ����������������Ҫ���  ��ȵı�ָ��������  ���ȵıߴӲ����յ����
//����n�������� ��Ϊs��������е����� s->t�����f=n��ɹ�  
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
//��㵼��2500*2=5000����
const int T = 2500;
const int N = 5002;
int flow[N][N],cap[N][N],p[N][N],path[N],son[N],g[N][N],a[N];
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };  
void add(int x, int y) {  
    cap[x][y] = 1;  
    g[x][son[x]++] = y;  //son[x]Ϊx�����ı��� g[i][j]Ϊi������j����Ϊ�յ�Ϊy
}
int r,c,n,tmp,f,s,t;
queue<int> Q;
void init() {  
  
    memset(g, 0, sizeof(g));  
    memset(son, 0, sizeof(son));  
  
    memset(cap, 0, sizeof(cap));  
    memset(flow, 0, sizeof(flow));  
  
    scanf("%d%d%d", &r, &c, &n);  
    tmp = 5001;  
  
    for (int i = 1; i <= r; i++) {  
  
        for (int j = 1; j <= c; j++) {  
  
            if (i == 1 || j == 1 || i == r || j == c)  
                add( (i-1) * c + j, 0);  
  
            add( (i-1) * c + j + T, (i-1) * c + j);  //��� ��i��Ϊ i+T->i
  
            for (int k = 0; k < 4; k++) {  
  
                int p = i + dir[k][0], q = j + dir[k][1];  
  
                if (p <= 0 || p > r) continue;  
                if (q <= 0 || q > c) continue;  
  
                add( (i-1) * c + j, (p-1) * c + q + T);  //i->p�ĵ��Ϊi+T->i->p+T(p+T->p)
            }  
        }  
    }  
  
    int a, b;  
    for (int i = 0; i < n; i++) {  
  
        scanf("%d%d\n", &a, &b);  
        add(tmp, (a-1) * c + b + T);      //tmp��Ϊ���  �����е�+T�ı�
    }  
}
int max_flow()
{
	f = 0;
	s = tmp;
	t = 0;
	memset(flow,0,sizeof(f));
	for(;;)
	{
		memset(a,0,sizeof(a));
		memset(path,0,sizeof(path));
		a[s] = INF;
		Q.push(s);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for(int i = 0;i<son[u];i++)
			{
				if(!a[g[u][i]]&&cap[u][g[u][i]]>flow[u][g[u][i]])
				{
					path[g[u][i]] = u;
					Q.push(g[u][i]);
					a[g[u][i]] = min(a[u],cap[u][g[u][i]]-flow[u][g[u][i]]);
				}
			}
		}
		if(a[t]==0) break;
		for(int i = t;i!=s;i=path[i])
		{
			flow[path[i]][i] += a[t];
			flow[i][path[i]] -= a[t];
		}
		f+=a[t];
	}
	return f;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cas;  
    scanf("%d", &cas);  
    while (cas--) {  
        init();  
  
        int ans = max_flow();  
        printf("%s\n", ans == n ? "possible" : "not possible");  
    }  
    return 0;
}

