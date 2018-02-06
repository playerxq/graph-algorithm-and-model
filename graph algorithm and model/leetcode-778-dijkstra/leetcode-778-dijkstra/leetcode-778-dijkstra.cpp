// leetcode-778-dijkstra.cpp : Defines the entry point for the console application.
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
#include <xfunctional>
#include <algorithm>
using namespace std;

class Solution {
public:
	int swimInWater(vector<vector<int>>& grid) {
		int n = grid.size();
		if (!n)
			return 0;
		int ans = max(grid[0][0],grid[n-1][n-1]);
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> Q;
		vector<vector<int>> vis(n,vector<int>(n,0));
		int dir[4][2] = { {0,-1},{0,1},{-1,0},{1,0} };
		vis[0][0] = 1;
		Q.push({ans,0,0});
		while (!Q.empty())
		{
			auto cur = Q.top();
			Q.pop();
			ans = max(ans,cur[0]);
			for (int i = 0; i < 4; i++)
			{
				int nx = cur[1] + dir[i][0];
				int ny = cur[2] + dir[i][1];
				if (nx >= 0 && nx < n&&ny >= 0 && ny < n&&vis[nx][ny] == 0)
				{
					vis[nx][ny] = 1;
					if (nx == n - 1 && ny == n - 1)
						return ans;
					Q.push({ grid[nx][ny],nx,ny});
				}
			}
		}
		return -1;
	}
};
int main()
{
    return 0;
}

