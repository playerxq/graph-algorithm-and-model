// leetcode-301-dfs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	void dfs(vector<string>& res, string s, string cs,int cur, int nl, int nr,int& minl,int* cnt)
	{
		if (nr > nl)
			return;
		if (s.length() == 0)
		{
			if (nr != nl)
				return;
			if (minl == -1)
			{
				minl = cs.length();
				res.push_back(cs);
				return;
			}
			if (cs.length() > minl)
			{
				minl = cs.length();
				res.clear();
				res.push_back(cs);
				return;
			}
			else if (cs.length() < minl)
				return;
			else
			{
				res.push_back(cs);
				return;
			}
		}
		if (s[0] != '('&&s[0] != ')')
		{
			dfs(res,s.substr(1),cs+s[0],cur+1,nl,nr,minl,cnt);
			return;
		}
		else
		{
			if (s[0] == '(')
			{
				if (cnt[cur]<nl-nr+1)
					dfs(res, s.substr(1), cs , cur + 1, nl, nr, minl,cnt);
				else
				{
					dfs(res, s.substr(1), cs + s[0], cur + 1, nl + 1, nr, minl, cnt);
					dfs(res, s.substr(1), cs, cur + 1, nl, nr, minl, cnt);
				}
			}
			else
			{
				if (nr+1>nl)
					dfs(res, s.substr(1), cs, cur + 1, nl, nr, minl, cnt);
				else
				{
					dfs(res, s.substr(1), cs, cur + 1, nl, nr, minl, cnt);
					dfs(res, s.substr(1), cs + s[0], cur + 1, nl, nr + 1, minl, cnt);
				}	
			}
		}
	}
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		if (s.length() == 0)
		{
			res.push_back("");
			return res;
		}
		string cs = "";
		int* cnt = new int[s.length()];
		for (int i = s.length()-1; i >=0; i--)
		{
			if (s[i] == ')')
			{
				if (i == s.length() - 1)
					cnt[s.length() - 1] = 1;
				else
					cnt[i] = cnt[i + 1] + 1;
			}
			else
				cnt[i] = cnt[i+1];
		}
		int len = -1;
		dfs(res,s,cs,0,0,0,len,cnt);
		sort(res.begin(),res.end());
		res.erase(std::unique(res.begin(),res.end()),res.end());
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.removeInvalidParentheses("(((()(()");
	return 0;
}

