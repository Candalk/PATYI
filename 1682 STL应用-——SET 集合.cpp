// 1682 STLӦ��-����SET ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{

	int n,flag=1;
	string name,S1;
	set<string> s;
	cin >> n>>name;
	for (int i = 0; i < n; i++) {
		cin >> S1;
		if (S1 == name) { flag = 0; continue; }
		else s.insert(S1);
	}
	if (flag == 1)cout << "song";
	else {
		for (set<string>::iterator i = s.begin(); i != s.end(); i++)
		{
			cout << *i << " ";
		}
	}
    return 0;
}

