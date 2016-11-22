// 1.cpp : 定义控制台应用程序的入口点。
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
#include <algorithm>
using namespace std;
int cmp(const void* _a, const void* _b)
{
	int* a = (int*)_a;
	int* b = (int*)_b;
	return (*a)>(*b);
}
int cmp1(const int a, const int b)
{
	return a>b;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int a[5] = {1,5,2,7,3};
	qsort(a,5,sizeof(a[0]),cmp);
	sort(a,a+5,cmp1);
	for(int i = 0;i<5;i++)
		printf("%d ",a[i]);
}

