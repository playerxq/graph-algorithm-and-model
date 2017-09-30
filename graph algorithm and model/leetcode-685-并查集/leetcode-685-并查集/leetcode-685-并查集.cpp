// leetcode-685-并查集.cpp : Defines the entry point for the console application.
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
	int root(vector<int>& parent, int k) {
		if (parent[k] != k)
			parent[k] = root(parent, parent[k]);
		return parent[k];
	}
	vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<int> parent(n + 1, 0), candA, candB;
		// step 1, check whether there is a node with two parents
		for (auto &edge : edges) {
			if (parent[edge[1]] == 0)
				parent[edge[1]] = edge[0];
			else {
				candA = { parent[edge[1]], edge[1] };//之前的那条边
				candB = edge;//现在的边
				edge[1] = 0;//让现在的边invalid
			}
		}
		// step 2, union find circle
		for (int i = 1; i <= n; i++)
			parent[i] = i;
		for (auto v : edges)
		{
			if (v[1] == 0)
				continue;
			int u1 = v[0];
			int v1 = v[1];
			int pu = root(parent, u1);
			// Now every node only has 1 parent, so root of v1 is implicitly v1
			if (pu == v1)
			{
				if (candA.empty())//
					return v;
				return candA;//让后面的那条多父节点边invalid之后还存在circle，因此应选择之前的那条多父节点边
			}
			parent[v1] = pu;
		}
		return candB;//没有circle 优先去除后面的边
	}
};
int main()
{
    return 0;
}

