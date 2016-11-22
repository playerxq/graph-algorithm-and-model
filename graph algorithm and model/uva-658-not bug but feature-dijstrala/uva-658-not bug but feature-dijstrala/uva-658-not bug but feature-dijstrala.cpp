// uva-658-not bug but feature-dijstrala.cpp : �������̨Ӧ�ó������ڵ㡣
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
using namespace std;
#define INF 1000000  
typedef struct {  
    int value;  
    int from[2], to[2];  
} Node;  

typedef pair<int, int> pill;
struct cmp
{
	bool operator () (const pill a, const pill b)
	{
		return a.first>b.first;
	}
};
Node Patch[110];  
int nBug, nPatch, success, vMin;  
int vis[2000000];
priority_queue<pill, vector<pill>,cmp > Q;
void Init()  
{  
    success = 0;  
    while(!Q.empty()) Q.pop();  
    memset(vis, 0, sizeof(vis));  
} 
void bfs()
{
	int t;
	Q.push(make_pair(0,(1<<nBug)-1));
	while(!Q.empty())
	{
		pill u = Q.top();
		Q.pop();
		if(u.second == 0) {  //�����յ�
            success = 1;  
            vMin = u.first;  
            return ;  
        }  
        if(vis[u.second])  
            continue;  
        vis[u.second] = 1;
		for(int i = 0; i < nPatch; i++) {  //��ĳ�������������������ɴӵ�ǰ״̬��չ��ȥ  �൱��һ����
            t = u.second;  
            if(((t) & Patch[i].from[0]) == Patch[i].from[0] && ((~t) & Patch[i].from[1]) == Patch[i].from[1]) {  
                t |= Patch[i].to[0];  //������©��
                t &= (~Patch[i].to[1]);  //ɾ���ɵ� 
                Q.push(make_pair(u.first + Patch[i].value, t));  
            }  
        }
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 int con = 1;  
    //freopen("text.in", "r", stdin);  
    char fir[110], sec[110];  
    while(scanf("%d %d", &nBug, &nPatch)) {  
        if(!nBug && !nPatch) break;  
        Init();  
        for(int i = 0; i < nPatch; i++) {  
            scanf("%d %s %s", &Patch[i].value, fir, sec);  
            Patch[i].from[0] = Patch[i].from[1] = Patch[i].to[0] = Patch[i].to[1] = 0;  
            for(int j = 0; j < nBug; j++) {  
                if(fir[j] == '+') Patch[i].from[0] |= (1 << (j)); //����Ĳ��� 
                if(fir[j] == '-') Patch[i].from[1] |= (1 << (j));  //����Ҫ��
            }  
            for(int j = 0; j < nBug; j++) {  
                if(sec[j] == '+') Patch[i].to[0] |= (1 << (j));  //��©��
                if(sec[j] == '-') Patch[i].to[1] |= (1 << (j));  //ȥ���ľ�©��
            }  
        }  
        bfs();  
        printf("Product %d\n", con++);  
        if(success) printf("Fastest sequence takes %d seconds.\n\n", vMin);  
        else printf("Bugs cannot be fixed.\n\n");  
    }  
    return 0; 
}

