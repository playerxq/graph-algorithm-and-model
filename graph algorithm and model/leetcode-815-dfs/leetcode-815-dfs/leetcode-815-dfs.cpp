// leetcode-815-dfs.cpp : Defines the entry point for the console application.
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
#include "iterator" 
using namespace std;
class Solution {
public:
	int is_com(int x, int y, vector<vector<int>>& routes)
	{
		sort(routes[x].begin(),routes[x].end());
		sort(routes[y].begin(), routes[y].end());
		vector<int> v;
		set_intersection(routes[x].begin(), routes[x].end(), routes[y].begin(), routes[y].end(), back_inserter(v));
		return v.size() != 0  ;
	}
	bool is_element_in_vector(vector<int>& v, int element) {
		vector<int>::iterator it;
		it = find(v.begin(), v.end(), element);
		if (it != v.end()) {
			return true;
		}
		else {
			return false;
		}
	}
	int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
		int n = routes.size();
		if (n == 1)
			return 1;
		vector<vector<int>> mp(n,vector<int>(n,0));
		vector<int> vis(n,0);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (is_com(i, j, routes))
				{
					mp[i][j] = mp[j][i] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (is_element_in_vector(routes[i], S))
			{
				vis[i] |= 4;
			}
			if (is_element_in_vector(routes[i], T))
			{
				vis[i] |= 2;
			}
		}
		int mi = INT_MAX;
		queue<int> Q;
		for (int i = 0; i < n; i++)
		{
			if ((vis[i] & 4) != 0)
			{
				if (S == T)
					return 0;
				Q.push(i);
				vis[i] |= 1;
			}
		}
		Q.push(-1);
		int res = 0;
		int pre = -2;
		while (!Q.empty())
		{
			int cur = Q.front();
			Q.pop();
			if (cur == -1)
			{
				if (pre == -1)
					break;
				res++;
				pre = -1;
				Q.push(-1);
				continue;
			}
			pre = cur;
			if ((vis[cur] & 2) != 0)
			{
				return res+1;
			}
			for (int i = 0; i < n; i++)
			{
				if (cur!=i&&mp[cur][i] == 1 && ((vis[i]&1)==0))
				{
					Q.push(i);
					vis[i] |= 1;
				}
			}
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> ve = { {7, 12},{4, 5, 15},{6},{15, 19},{9, 12, 13} };
	//vector<vector<int>> ve = { {2},{2,8} };
	s.numBusesToDestination(ve,8,2);
    return 0;
}

