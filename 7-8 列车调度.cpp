// 7-8 列车调度.cpp : 定义控制台应用程序的入口点。
//这个

#include "stdafx.h"
#include<iostream>
#include<set>
using namespace std;
int main()
{
	int N,tmp,num=0;
	cin >> N;
	set<int> s;
	s.insert(0);
	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		if (*s.rbegin() > tmp)
			s.erase(*(s.upper_bound(tmp)));
		s.insert(tmp);
	}
	cout << s.size()-1;
    return 0;
}
