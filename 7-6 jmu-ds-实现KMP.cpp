// 7-6 jmu-ds-ʵ��KMP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string S, T;
	for (int i = 0; i < n; i++) {
		int flag = -1;
		cin >> S >> T;
		for (int j = 0; j < S.size() - T.size(); j++) {
			if (S.substr(j, T.size()) == T) { flag = j; break; }
		}
		if (flag == -1)cout << "not find!" << endl;
		else cout << flag << endl;
	}
    return 0;
}

