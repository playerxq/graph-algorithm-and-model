// hdu-1104-bfs.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int M = 1000010;

int n, m, k, km;
bool vis[M];

struct Node
{
    int num;
    int step;
    string road;
};
void bfs()
{
	memset(vis, 0, sizeof(vis));
    queue <Node> q;
    Node q1;
    q1.num = n;
    q1.step = 0;
    q1.road = "";
    q.push(q1);
    vis[(n % k + k) % k] = 1;
	while (!q.empty())
	{
		Node q2 = q.front();
        q.pop();
		if (((n+1)%k + k) % k == (q2.num%k + k) % k)
		{
			printf("%d\n", q2.step);
            cout << q2.road << endl;
            return;
		}
		q1.step = q2.step + 1;
		for (int i = 0; i < 4; i++)
		{
			if(i==0)
			{
				q1.num = (q2.num + m) % km;//取余就可以了，不需要取mod
                q1.road = q2.road + '+';//记录路径
			}
			else if(i==1)
			{
				q1.num = (q2.num - m) % km;
                q1.road = q2.road + '-';
			}
			else if(i==2)
			{
				q1.num = (q2.num * m) % km;
                q1.road = q2.road + '*';
			}
			else
			{
				q1.num = (q2.num % m + m) % m % km;
                q1.road = q2.road + '%';
			}
			if (!vis[(q1.num % k + k) % k])
            {
                q.push(q1);
                vis[(q1.num % k + k) % k] = 1;
            }
		}
	}
	puts("0");
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while (~scanf("%d%d%d", &n, &k, &m), n||m||k)
	{
		km = k * m;
		bfs();
	}
}

