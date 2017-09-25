// leetcode-684-²¢²é¼¯.cpp : Defines the entry point for the console application.
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
	int find(vector<int>& ve, int k)
	{
		if (ve[k] != k)
			ve[k] = find(ve,ve[k]);
		return ve[k];
	}
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> ve;
		for (int i = 0; i < 2001; i++)
			ve.push_back(i);
		for (auto ed : edges)
		{
			int pa = find(ve,ed[0]);
			int pb = find(ve,ed[1]);
			if (pa == pb)
				return ed;
			ve[pb] = pa;
		}
		return vector<int>(0,0);
	}
};
int main()
{
    return 0;
}

