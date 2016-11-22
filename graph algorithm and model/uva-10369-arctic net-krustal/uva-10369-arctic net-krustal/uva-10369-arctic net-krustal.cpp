// uva-10369-arctic net-krustal.cpp : 定义控制台应用程序的入口点。
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
const int MAXND = 1001;  
const int MAXNE = 500505;  
int n, m, s, p[MAXND];  
int u[MAXNE], v[MAXNE], r[MAXNE];  
double w[MAXNE];  
int cmp(const int i, const int j)  
{  
    return w[i] < w[j];  
}  
int find(int x)
{
	return p[x]==x?x:(p[x] = find(p[x]));
}
void kruskal()  
{  
    int cct = 0;  
    for(int i=0; i<s; i++)  
        p[i] = i;  
    for(int i=0; i<m; i++)  
        r[i]=i;  
    sort(r, r+m, cmp);  
    for(int i=0; i<m; i++)  
    {  
        int e = r[i];  
        int x = find(u[e]);  
        int y = find(v[e]);  
        if(x != y)  
        {  
            p[x] = y;  
            ++cct;  
            if(cct == s - n) // 第p-s大的边  
            {  
                printf("%.2lf\n", w[e]);  
                return ;  
            }  
        }  
    }  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int num;  
    double x[MAXND], y[MAXND];  
    scanf("%d", &num);  
    while(num--)  
    {  
        m = 0;  
        scanf("%d%d", &n, &s);  
        for(int i=0; i<s; i++)  
            scanf("%lf%lf", &x[i], &y[i]);  
        for(int i=0; i<s; i++)  
            for(int j=i+1; j<s; j++)  
            {  
                u[m] = i;  
                v[m] = j;  
                double d1 = x[i] - x[j];  
                double d2 = y[i] - y[j];  
                w[m++] = sqrt(d1*d1 + d2*d2);  
            }  
        kruskal();  
    }  
    return 0;  
}

