// uva-10048-audiophobia-floyd.cpp : 定义控制台应用程序的入口点。
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
int f[110][110];
int main()
{
    int i,j,k,n,t,C,S,Q,u,v,temp;
    t=0;
    while(scanf("%d%d%d",&C,&S,&Q)==3)
    {
        if(C==0)
            break;
        for(i=1;i<=C;i++)
            for(j=1;j<=C;j++)
            {
                if(i==j)
                    f[i][j]=0;
                else
                    f[i][j]=-1;
            }
        for(i=0;i<S;i++)
        {
            scanf("%d%d%d",&u,&v,&k);
            f[u][v]=f[v][u]=k;
        }
        for(k=1;k<=C;k++)
            for(i=1;i<=C;i++)
                for(j=1;j<=C;j++)
                    if(f[i][k]!=-1&&f[k][j]!=-1)
                    {
                        temp=f[i][k]>f[k][j]?f[i][k]:f[k][j];
                        if(f[i][j]==-1||temp<f[i][j])
                            f[i][j]=temp;
                    }
        if(t++)
            printf("\n");
        printf("Case #%d\n",t);
        for(i=0;i<Q;i++)
        {
            scanf("%d%d",&u,&v);
            if(f[u][v]==-1)
                printf("no path\n");
            else
                printf("%d\n",f[u][v]);
        }
    }
    return 0;
}

