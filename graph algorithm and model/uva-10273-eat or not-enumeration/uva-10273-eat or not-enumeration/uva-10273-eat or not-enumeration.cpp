// uva-10273-eat or not-enumeration.cpp : �������̨Ӧ�ó������ڵ㡣
//nͷţ��ÿͷ�в������ڣ�����Ҫɱţ������������ҵ�������С��ţ��ֻ��Ϊ1���Ϳ�ɱ
//�����ʣ��ͷţ�����ɱţ��������

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
#define MAXD 1010
#define INF 1000000000
int N, T, t[MAXD], d[MAXD][20], U[MAXD], D[MAXD], st[MAXD];//u[i] d[i]Ϊi���������� ����
//st[i]Ϊ��iͷţ���ǵ��ڼ��� ����������ÿ��ţ�Ĳ������ڵ�ģ  ÿ��ţ��������

int gcd(int a, int b)
{
	return b==0?a:gcd(b,a%b);
}
void init()
{
    int i, j, k;
    scanf("%d", &N);
    for(i = 1; i <= N; i ++)
    {
        scanf("%d", &t[i]);
        for(j = 0; j < t[i]; j ++)//��iͷţ��j�������
            scanf("%d", &d[i][j]);
    }
    for(i = 0; i <= N; i ++)//��ʼ������
    {
        D[i] = i + 1;
        U[i + 1] = i;
    }
    D[N] = 0;//ѭ����
    memset(st, 0, sizeof(st));
    T = 1;
    for(i = 1; i <= N; i ++)
    {
        if(T < t[i])
            k = gcd(t[i], T);
        else
            k = gcd(T, t[i]);
        T = T * t[i] / k;//lcm  ������
    }
}
void solve()
{
    int i, j, k, cur, min, num, flag, a, p, sum;
    num = min = 0;
    for(p = 0;;p++)//�Ѿ���������
	{
		flag =0;
		for(cur = 1;cur<=T;cur++)//�鿴һ��������ɱţ���Լ����ɱţ����
		{
			a = INF;
			for(i = D[0];i!=0;i = D[i])
			{
				if(d[i][st[i]]<a)//�ҵ����������С��ţ
				{
					a = d[i][st[i]];
					k = i;
					sum = 1;
				}
				else if(d[i][st[i]]==a)
					sum++;
				st[i] = (st[i]+1)%t[i];//ÿ��ţ������һ��
			}
			if(sum==1)
			{
				flag = 1;
				U[D[k]] = U[k];
				D[U[k]] = D[k];
				min = p*T+cur;//���ɱţ����
				num++;
			}
		}
		if(!flag)//��ǰһ��T������û��ţ��ɱ �ȶ�
			break;
	}
    printf("%d %d\n", N - num, min);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
    scanf("%d", &test);
    while(test --)
    {
        init();
        solve();
    }
    return 0;
}

