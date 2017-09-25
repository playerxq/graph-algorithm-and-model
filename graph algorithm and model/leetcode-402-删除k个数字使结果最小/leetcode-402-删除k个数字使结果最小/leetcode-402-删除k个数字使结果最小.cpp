// leetcode-402-删除k个数字使结果最小.cpp : 定义控制台应用程序的入口点。
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
	string removeKdigits(string num, int k) {
		string res = "";
		int n = num.size(), keep = n - k;
		for (char c : num) {
			while (k && res.size() && res.back() > c) {
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}
		res.resize(keep);
		while (!res.empty() && res[0] == '0') res.erase(res.begin());
		return res.empty() ? "0" : res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.removeKdigits("112",1);
	return 0;
}

