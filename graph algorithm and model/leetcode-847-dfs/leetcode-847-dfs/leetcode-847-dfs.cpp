// leetcode-847-dfs.cpp : Defines the entry point for the console application.
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


class Solution {
public:
	int res;
	void dfs(vector<vector<int>>& graph, vector<int>& cur, vector<int>& visited, int count)
	{
		if (res == graph.size()) return;
		if (count == graph.size()) {
			res = min(res, int(cur.size()));
			return;
		}
		if (cur.size() >= res) return;
		int pos = cur.back();
		int minv = INT_MAX;
		for (auto n : graph[pos]) minv = min(minv, visited[n]);
		for (auto n : graph[pos])
		{
			if (visited[n] == minv)
			{
				cur.push_back(n);
				if (!visited[n]) count++;
				visited[n]++;
				dfs(graph, cur, visited, count);
				visited[n]--;
				if (!visited[n]) count--;
				cur.pop_back();
			}
		}
	}
	int shortestPathLength(vector<vector<int>>& graph) {
		res = INT_MAX;
		vector<int> cur;
        vector<int> visited(graph.size(), 0);
        int count = 0;
		for (int i = 0; i < graph.size(); i++)
		{
			cur.push_back(i);
			visited[i] = 1;
			count++;
			dfs(graph, cur, visited, count);
			count--;
			visited[i]--;
			cur.pop_back();
		}
		return res - 1;
	}
};
int main()
{
    return 0;
}

