// leetcode-817-Á´±í.cpp : Defines the entry point for the console application.
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		int n = G.size();
		if (!n)
			return 0;
		int res = 0;
		set<int> se = {G.begin(),G.end()};
		map<int, set<int>> mp;
		ListNode* cur = head;
		while (cur)
		{
			if (se.count(cur->val) == 0)
			{
				cur = cur->next;
			}
			else
			{
				set<int> ve;
				int t = cur->val;
				while (cur)
				{
					if (se.count(cur->val))
					{
						ve.insert(cur->val);
						cur = cur->next;
					}
					else
						break;
				}
				mp[t] = ve;
			}
		}
		for (map<int, set<int>>::iterator it1 = mp.begin(); it1 != mp.end(); it1++)
		{
			for (map<int, set<int>>::iterator it2 = mp.begin(); it2 != mp.end(); it2++)
			{
				if (it1 == it2)
					continue;
				if ((it2->second.count(it1->first)) || (it1->second.count(it2->first)))
				{
					it1->second.insert(it2->second.begin(),it2->second.end());
					it2->second.clear();
				}
			}
		}
		for (map<int, set<int>>::iterator it1 = mp.begin(); it1 != mp.end(); it1++)
		{
			if (it1->second.size())
				res++;
		}
		return res;
	}
};
int main()
{
	Solution s;
	ListNode* head = new ListNode(0);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	vector<int> G = {0,1,3};
	s.numComponents(head, G);
    return 0;
}

