// uva-10608-friends-并查集.cpp : 定义控制台应用程序的入口点。
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
const int MAXN = 30002;  
int friends[MAXN], p[MAXN];  
int find(int x)  
{  
    return p[x] == x ? x : (p[x] =find(p[x]));  
}  
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m, n, t, x, y, u, v, _max;  
    scanf("%d", &t);  
    while(t--)  
    {  
        _max = 0;  
        scanf("%d%d", &n, &m);  
        memset(friends, 0, (n+1)*sizeof(friends[0]));  
        for(int i=1; i<=n; i++)  
            p[i] = i;  
        for(int i=0; i<m; i++)  
        {  
            scanf("%d%d", &x, &y);  
            u = find(x);  
            v = find(y);  
            if(u != v)  
                p[u] = v;  
        }  
        for(int i=1; i<=n; i++)  
        {  
            x = find(i);  
            ++friends[x];  
        }  
        for(int i=1; i<=n; i++)  
            if(friends[i] > _max)  
                _max = friends[i];  
        printf("%d\n", _max);  
    }  
    return 0;
}

