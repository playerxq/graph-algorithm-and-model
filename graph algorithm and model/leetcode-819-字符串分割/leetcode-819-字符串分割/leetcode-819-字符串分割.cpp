// leetcode-819-×Ö·û´®·Ö¸î.cpp : Defines the entry point for the console application.
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
	string mostCommonWord(string paragraph, vector<string>& banned) {
		vector<string> ve;
		int pos = 0;
		int len = paragraph.size();
		for (int i = 0; i < len; i++)
		{
			if (paragraph[i] >= 'A'&&paragraph[i] <= 'Z')
			{
				paragraph[i] ^= 1 << 5;
			}
			else if (paragraph[i] < 'a'||paragraph[i] > 'z')
			{
				paragraph[i] = ' ';
			}
		}
		int s = 0;
		while (s < len&&paragraph[s] == ' ')
			s++;
		for (int i = s; i < len; i++)
		{
			if (paragraph[i] != ' ')
				continue;
			else
			{
				ve.push_back(paragraph.substr(s,i-s));
				s = i + 1;
				while (s < len&&paragraph[s] == ' ')
					s++;
				i = s-1;
			}
		}
		if (s < len)
			ve.push_back(paragraph.substr(s));
		int n = ve.size();
		map<string, int> mp;
		int f = 1;
		for (int i = 0; i < n; i++)
		{
			f = 1;
			for (int j = 0; j < banned.size()&&f; j++)
				if (ve[i] == banned[j])
					f = 0;
			if (f == 1 && !mp.count(ve[i]))
			{
				mp.insert(make_pair(ve[i], 1));
			}
			else if (f == 1)
				mp[ve[i]]++;
			else
				continue;
		}
		int mx = INT_MIN;
		string res;
		for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second > mx)
			{
				res = it->first;
				mx = it->second;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<string> ve = {  };
	s.mostCommonWord("a.",ve);
    return 0;
}

