// leetcode-207-判断是否有环.cpp : 定义控制台应用程序的入口点。
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
	int dfs(int i, int* vis, int* head, int* nx, int* lk)
	{
		vis[i] = -1;
		int s = head[i];
		for(;s!=-1;s = nx[s])
		{
			int e = lk[s];
			if(vis[e]==-1)
				return 0;
			else if(vis[e]==1)
				continue;
			else
			{
				int res = dfs(e,vis,head,nx,lk);
				if(!res)
					return 0;
			}
		}
		vis[i] = 1;
		return 1;
	}
    bool canFinish(int n, vector<pair<int, int>>& ve) {
        int cnt = ve.size();
		int* head = new int[n+1];
		int* nx = new int[cnt+1];
		int* vis = new int[n+1];
		int* lk = new int[cnt+1];
		int id = 0;
		for(int i = 0;i<n;i++)
		{
			head[i] = -1;
			vis[i] = 0;
		}
		for(int i = 0;i<cnt;i++)
		{
			nx[i] = -1;
		}
		for(int i = 0;i<ve.size();i++)
		{
			int st = ve[i].second;
			int ed = ve[i].first;
			int pre = head[st];
			head[st] = id;
			nx[id] = pre;
			lk[id++] = ed;
		}
		for(int i = 0;i<n;i++)
		{
			if(vis[i]==0)
			{
				int f = dfs(i,vis,head,nx,lk);
				if(f==0)
					return false;
			}
		}
		return true;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<pair<int, int>> ve;
	ve.push_back(make_pair(0,1));
	s.canFinish(2,ve);
	return 0;
}

