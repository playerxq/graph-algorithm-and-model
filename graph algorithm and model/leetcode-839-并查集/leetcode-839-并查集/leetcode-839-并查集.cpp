// leetcode-839-²¢²é¼¯.cpp : Defines the entry point for the console application.
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
	string getfather(string s, unordered_map<string, string> &mapping) {
		string temp = mapping[s];
		if (temp != s) return getfather(temp, mapping);
		else return temp;
	}
	bool isSimilar(string &a, string &b) {
		int n = a.length(), counter = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) counter++;
		}
		return counter == 2;
	}
	int numSimilarGroups(vector<string>& A) {
		unordered_map<string, string> mapping;
		int n = A.size();
		for (int i = 0; i < n; i++)
		{
			if(mapping.find(A[i]) != mapping.end()) continue;
			mapping[A[i]] = A[i];
			for (int j = 0; j < i; j++)
			{
				if (isSimilar(A[i], A[j]) && mapping[A[j]] != A[i])
				{
					string x = getfather(A[j], mapping);
					mapping[x] = A[i];
				}
			}
		}
		int result = 0;
		for (auto it = mapping.begin(); it != mapping.end(); it++) {
			if (it->first == it->second) result++;
		}
		return result;
	}
};
int main()
{
    return 0;
}

