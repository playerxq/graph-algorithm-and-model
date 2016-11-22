// uva-10397-connect-krustal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
const int DMAXN = 755;  
const int EMAXN = 281630;  
int n, p[DMAXN], u[EMAXN], v[EMAXN], r[EMAXN];  
double x[DMAXN], y[DMAXN], dis[EMAXN], ans;  
bool vis[DMAXN][DMAXN];  
int cmp(const int i, const int j)  
{  
    return dis[i] < dis[j];  
}  
int find(int i)  
{  
    return p[i] == i ? i : (p[i] = find(p[i]));  
}
void Kruskal()  
{  
    ans = 0;  
    sort(r, r+n, cmp);  
    for(int i=0; i<n; i++)  
    {  
        int e = r[i];  
        int xx = find(u[e]);  
        int yy = find(v[e]);  
        if(xx != yy)  
        {  
            ans += dis[e];  
            p[xx] = yy;  
        }  
    }  
} 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int dot, cable, fx, fy;  
    while(scanf("%d", &dot) != EOF)  
    {  
        n = 0;  
        double d1, d2;  
        memset(vis, false, sizeof(vis));  
        for(int i=0; i<dot; i++)  
        {  
            scanf("%lf%lf", &x[i], &y[i]);  
            p[i] = i;  
        }  
        scanf("%d", &cable);  
        for(int i=0; i<cable; i++)  
        {  
            scanf("%d%d", &fx, &fy);  
            --fx;  
            --fy;  
            vis[fx][fy] = vis[fy][fx] = true;  
        }  
        for(int i=0; i<dot; i++)  
            for(int j=i+1; j<dot; j++)  
            {  
                u[n] = i;  
                v[n] = j;  
                r[n] = n;  
                if(vis[i][j])  
                    dis[n++] = 0.0;  
                else  
                {  
                    d1 = x[i] - x[j];  
                    d2 = y[i] - y[j];  
                    dis[n++] = sqrt(d1*d1+d2*d2);  
                }  
            }  
        Kruskal();  
        printf("%.2lf\n", ans);  
    }  
    return 0;
}

