// uva-10099-tourist guide-floyd.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;
int vis[101][101];
const int INF = 1000003;
void floyd(int n)
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                vis[i][j] = max(vis[i][j],min(vis[i][k], vis[k][j]));
}
int main()
{
    int n, r, x, y, w;
    int start, end, cas = 0, mod;
    while(scanf("%d%d", &n, &r))
    {
        if(!n && !r)
            break;
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<r; i++)
        {
            scanf("%d%d%d", &x, &y, &w);
            vis[y][x] = vis[x][y] = w;
        }
        scanf("%d%d%d", &start, &end, &w);
        floyd(n);
        printf("Scenario #%d\n", ++cas);
        mod = 0;
        if(w % (vis[start][end]-1))
            mod = 1;
        printf("Minimum Number of Trips = %d\n", w / (vis[start][end]-1) + mod);//每一趟最多只能运 max_val-1 个人，因为导游每次还要站一个位置
        puts("");
    }
    return 0;
}


