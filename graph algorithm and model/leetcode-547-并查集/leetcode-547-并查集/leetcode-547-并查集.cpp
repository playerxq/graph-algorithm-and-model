// leetcode-547-并查集.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Union
{
public:
	vector<int> p;
	vector<int> rank;
	int cnt = 0;
	Union(int n)
	{
		cnt = n;
		for (int i = 0; i < n; i++)
		{
			p.push_back(i);
			rank.push_back(0);
		}
	}
	int find(int par)
	{
		while (par != p[par])
		{
			p[par] = p[p[par]];
			par = p[par];
		}
		return par;
	}
	void uni(int p1, int p2)
	{
		int r1 = find(p1);
		int r2 = find(p2);
		if (r1 == r2)
			return;
		if (rank[r2] > rank[r1])
			p[r1] = r2;
		else
		{
			p[r2] = r1;
			if (rank[r1] == rank[r2])
				rank[r1]++;
		}
		cnt--;
	}
	int count()
	{
		return cnt;
	}
};
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		Union* uf = new Union(n);
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (M[i][j] == 1)
					uf->uni(i,j);
			}
		}
		return uf->count();
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	vector<vector<int>> M = { {1,1,0}, {1,1,0}, {0,0,1} };
	Solution s;
	s.findCircleNum(M);
	return 0;
}

