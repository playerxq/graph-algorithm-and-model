// leetcode-399-并查集.cpp : 定义控制台应用程序的入口点。
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
	int dfs(map<string, vector<string>>& ed, map<pair<string, string>, double>& E, map<string, int>& vis, string st, string et,double& res)
	{
		if (vis[st])
			return 0;
		if (E.count(make_pair(st, et)) != 0)
		{
			res *= E[make_pair(st, et)];
			return 1;
		}
		vis[st] = 1;
		for (int i = 0; i < ed[st].size(); i++)
		{
			if (vis[ed[st][i]])
				continue;
			double tmp = 1.0;
			if (dfs(ed, E, vis,ed[st][i], et,tmp))
			{
				E[make_pair(ed[st][i], et)] = tmp;
				E[make_pair(et, ed[st][i])] = 1.0/tmp;
				res *= (E[make_pair(st, ed[st][i])] * tmp);
				vis[st] = 0;
				return 1;
			}
			tmp = 1.0;
		}
		vis[st] = 0;
		return 0;
	}
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		map<string, vector<string>> ed;
		map<string, int> vis;
		map<pair<string, string>, double> E;
		for (int i = 0,j =0; i < equations.size(); i++,j++)
		{
			E[make_pair(equations[i].first, equations[i].first)] = 1;
			E[make_pair(equations[i].second, equations[i].second)] = 1;
			if (equations[i].first == equations[i].second)
			{
				continue;
			}
			vis[equations[i].first] = 0;
			vis[equations[i].second] = 0;
			ed[equations[i].first].push_back(equations[i].second);
			ed[equations[i].second].push_back(equations[i].first);
			E[make_pair(equations[i].first, equations[i].second)] = values[j];
			E[make_pair(equations[i].second, equations[i].first)] = (1.0/values[j]);
		}
		vector<double> res;
		for (int i = 0; i < queries.size(); i++)
		{
			if ((E.count(make_pair(queries[i].first, queries[i].second)) != 0) || (E.count(make_pair(queries[i].second, queries[i].first)) != 0))
			{
				if (E.count(make_pair(queries[i].first, queries[i].second)) != 0)
				{
					res.push_back(E[make_pair(queries[i].first, queries[i].second)]);
				}
				else
				{
					res.push_back(1.0/E[make_pair(queries[i].second, queries[i].first)]);
				}
			}
			else
			{
				double rr = 1.0;
				if (dfs(ed, E, vis, queries[i].first, queries[i].second,rr))
				{
					E[make_pair(queries[i].first, queries[i].second)] = rr;
					E[make_pair(queries[i].second, queries[i].first)] = 1.0/rr;
					res.push_back(rr);
				}
				else
				{
					res.push_back(-1.0);
				}
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	vector<pair<string, string>> v1;
	vector<double> v2;
	vector<pair<string, string>> v3;
	v1.push_back(make_pair("x1","x2"));
	v1.push_back(make_pair("x2", "x3"));
	v1.push_back(make_pair("x3", "x4"));
	v1.push_back(make_pair("x4", "x5"));
	v2.push_back(3.0);
	v2.push_back(4.0);
	v2.push_back(5.0);
	v2.push_back(6.0);
	v3.push_back(make_pair("x1","x5"));
	v3.push_back(make_pair("x5", "x2"));
	v3.push_back(make_pair("x2", "x4"));
	v3.push_back(make_pair("x2", "x2"));
	v3.push_back(make_pair("x2", "x9"));
	v3.push_back(make_pair("x9", "x9"));
	Solution s;
	s.calcEquation(v1,v2,v3);
	return 0;
}

