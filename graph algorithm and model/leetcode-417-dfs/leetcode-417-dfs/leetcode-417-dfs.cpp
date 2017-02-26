// leetcode-417-dfs.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	int m;
	int n;
	vector<pair<int, int>> res;
	void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& matrix, vector<vector<int>>& dir, int preval)
	{
		if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()
			|| (vis[x][y] & preval) == preval)
			return;
		vis[x][y] |= preval;
		if (vis[x][y] == 3)
			res.push_back(make_pair(x,y));
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if ((nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size()))
				continue;
			if (matrix[nx][ny]<matrix[x][y])
				continue;
			dfs(nx,ny,vis,matrix,dir,vis[x][y]);
		}
		return;
	}
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		
		m = matrix.size();
		if (!m)
			return res;
		n = matrix[0].size();
		vector<vector<int>> dir = { { -1, 0 }, { 1, 0 }, { 0, -1 }, {0,1} };
		vector<vector<int>> vis(m+1,vector<int>(n+1,0));
		for (int i = 0; i < n; i++)
		{
			dfs(0, i, vis, matrix, dir, 1);
			if (m>=1)
				dfs(m-1, i, vis, matrix, dir, 2);
		}
		for (int i = 0; i < m; i++)
		{
			dfs(i, 0, vis, matrix, dir, 1);
			if (n>=1)
				dfs(i, n-1, vis, matrix, dir, 2);
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

