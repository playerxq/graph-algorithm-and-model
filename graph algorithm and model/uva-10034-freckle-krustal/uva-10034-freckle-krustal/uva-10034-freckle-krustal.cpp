// uva-10034-freckle-krustal.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
#include<stdlib.h>
using namespace std;

double x[110],y[110],w[10010];
int u[10010],v[10010],p[110],r[10010];
int cmp(const void *_p,const void *_q)//升序
{
    int *p=(int *)_p;
    int *q=(int *)_q;
    return w[*p]>w[*q]?1:-1;
}
int find(int x)//并查集
{
	return p[x]==x?x:(p[x] = find(p[x]));
}
double distance(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));    
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,k,n,t,e,tx,ty;
    double ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf%lf",&x[i],&y[i]);
        e=0;
        for(i=0;i<n;i++)
		{
            for(j=i+1;j<n;j++)
            {
                u[e]=i;
                v[e]=j;
                w[e]=distance(i,j);
                e++;
            }
		}
        for(i=0;i<n;i++)//并查集初始化
            p[i]=i;
        for(i=0;i<e;i++)
            r[i]=i;
        qsort(r,e,sizeof(r[0]),cmp);
        ans=0.0;
        for(i=0;i<e;i++)
        {
            tx=find(u[r[i]]);
            ty=find(v[r[i]]);
            if(tx!=ty)
            {
                p[tx]=ty;
                ans+=w[r[i]];
            }
        }
        printf("%.2f\n",ans);
        if(t)
            printf("\n");
    }
    return 0; 
}

