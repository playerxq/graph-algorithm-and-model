// test2.cpp : 定义控制台应用程序的入口点。
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
int get_c()
{
	int sum = 0;
	for(int a1 = 0;a1<=9;a1++)
	{
		for(int a2 = a1;a2<=9;a2++)
		{
			for(int a3 = a2;a3<=9;a3++)
			{
				for(int a4 = a3;a4<=9;a4++)
				{
					for(int a5 = a4;a5<=9;a5++)
					{
						sum++;
						printf("%d %d %d %d %d\n",a1,a2,a3,a4,a5);
					}
				}
			}
		}
	}
	return sum;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	printf("%d\n",get_c());
	return 0;
}

