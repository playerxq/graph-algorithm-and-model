// uva-10158-war-并查集.cpp : 定义控制台应用程序的入口点。
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
int p[20005];  
int n;
int find(int x)  
{  
    return p[x]==x?x:p[x]=find(p[x]);  
}
//1:n保存friend  n+1:2n为enemy 
int areFriends(int x,int y)  
{  
    if(find(x)!=find(y)&&find(x)!=find(y+n)) return -1;  //关系未知
    if(find(x)==find(y)) return 1;  
    if(find(x)!=find(y)) return 0;  
}  
int areEnemies(int x,int y)  
{  
    if(find(x)!=find(y)&&find(x)!=find(y+n)) return -1;  
    if(find(x)!=find(y)) return 1;  
    if(find(x)==find(y)) return 0;  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,x,y;  
    cin>>n;  
    for(int i=1;i<=2*n;i++)  
        p[i]=i;  
    cin>>t>>x>>y;
	while(t||x||y)  
    {  
        if(t==1)   
        {  
            if(areFriends(x,y)==0) cout<<"-1"<<endl;  
            if(areFriends(x,y)==-1)  
            {  
                p[find(x)]=find(y);  //x y为朋友
                p[find(x+n)]=find(y+n);  //x y的敌人成为朋友
            }  
  
        }  
        if(t==2)  
        {  
            if(areEnemies(x,y)==0) cout<<"-1"<<endl;  
            if(areEnemies(x,y)==-1)  
            {  
                p[find(x+n)]=find(y);  // x的敌人是y的朋友
                p[find(x)]=find(y+n);  //x是y敌人的朋友
            }  
        }  
        if(t==3)  
        {  
            if(areFriends(x,y)==1) cout<<"1"<<endl;  
            else cout<<"0"<<endl;  
        }  
        if(t==4)  
        {  
            if(areEnemies(x,y)==1) cout<<"1"<<endl;  
            else cout<<"0"<<endl;  
        }  
        cin>>t>>x>>y;  
    }  
    return 0; 
}

