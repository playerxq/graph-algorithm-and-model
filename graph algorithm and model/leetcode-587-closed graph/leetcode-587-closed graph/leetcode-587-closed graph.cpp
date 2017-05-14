// leetcode-587-closed graph.cpp : 定义控制台应用程序的入口点。
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
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
	static int distSq(Point p1, Point p2) {
		return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}
	static int orientation(Point p, Point q, Point r)
	{
		int t = (q.y - p.y)*(r.x - q.x) - (q.x - p.x) * (r.y - q.y);
		if (t == 0)
			return 0;
		if (t > 0)
			return 1;
		return 2;
	}
	struct pointCom
	{
		Point p0;
		pointCom(Point p)
		{
			p0 = p;
		}
		bool operator ()(const Point& p1, const Point& p2)
		{
			int t = orientation(p0,p1,p2);
			if (t == 0)
			{
				return distSq(p0, p1) <= distSq(p0,p2);
			}
			return t == 2;
		}
	};
	vector<Point> outerTrees(vector<Point>& points) {
		int n = points.size();
		if (n <= 3) {
			return points;
		}
		int ymin = points[0].y;
		int min = 0;
		for (int i = 1; i < n; i++)
		{
			if (points[i].y < ymin || (points[i].y == ymin&&points[i].x < points[min].x))
			{
				min = i;
				ymin = points[i].y;
			}
		}
		Point tt = points[0];
		points[0] = points[min];
		points[min] = tt;
		Point p0 = points[0];
		sort(points.begin(),points.end(),pointCom(p0));
		Point pn = points.back();
		if (orientation(p0, points[1], pn) != 0)
		{
			int id = n - 1;
			while (orientation(p0, points[id], pn) == 0)
				id--;
			reverse(points.begin()+id+1,points.end());
		}
		vector<Point> vertices;
		vertices.push_back(points[0]);
		vertices.push_back(points[1]);
		vertices.push_back(points[2]);
		for (int i = 3; i < n; i++)
		{
			while (orientation(vertices[vertices.size()-2],vertices[vertices.size()-1],points[i]) == 1)
				vertices.pop_back();
			vertices.push_back(points[i]);
		}
		return vertices;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

