// leetcode-332-dfs with stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <set>
#include<stack>
#include <unordered_map>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		unordered_map<string, multiset<string>> graph;
		vector<string> res;
		if (tickets.size() == 0)
			return res;
		for (pair<string, string> eachTicket : tickets){
			graph[eachTicket.first].insert(eachTicket.second);
		}
		stack<string> dfs;
		dfs.push("JFK");
		while (!dfs.empty()){
			string topAirport = dfs.top();
			if (graph[topAirport].empty()){
				res.push_back(topAirport);
				dfs.pop();
			}
			else {
				dfs.push(*(graph[topAirport].begin()));
				graph[topAirport].erase(graph[topAirport].begin());
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

