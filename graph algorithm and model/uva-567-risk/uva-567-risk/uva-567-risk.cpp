// uva-567-risk.cpp : 定义控制台应用程序的入口点。
//floyd

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
int f[30][30];
int main()
{
    int i,j,k,n,u,v,t;
    t=0;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=20;i++)
            for(j=1;j<=20;j++)
            {
                if(i==j)
                    f[i][j]=0;
                else
                    f[i][j]=1000003;
            }
        for(j=0;j<n;j++)
        {
            scanf("%d",&v);
            f[1][v]=f[v][1]=1;
        }
        for(i=2;i<=19;i++)
        {
            scanf("%d",&n);
            for(j=0;j<n;j++)
            {
                scanf("%d",&v);
                f[i][v]=f[v][i]=1;
            }
        }
        for(k=1;k<=20;k++)
            for(i=1;i<=20;i++)
                for(j=1;j<=20;j++)
                    if(f[i][k]+f[k][j]<f[i][j])
                        f[i][j]=f[i][k]+f[k][j];
        printf("Test Set #%d\n",++t);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            printf("%2d to %2d: %d\n",u,v,f[u][v]);
        }
        printf("\n");
    }
    return 0;    
}

