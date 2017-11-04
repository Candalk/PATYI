// 7-3 两个有序链表序列的交集.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<int> v1, v2, v3;
	int temp;
	cin >> temp;
	while (temp != -1) {
		v1.push_back(temp);
		cin >> temp;
	}
	cin >> temp;
	while (temp != -1) {
		v2.push_back(temp);
		cin >> temp;
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int i = 0, j = 0;
	while (i < v1.size() && j < v2.size()) {
		if (v1[i] == v2[j]) {
			v3.push_back(v1[i]);
			i++; j++;
		}
		else if (v1[i] < v2[j])i++;
		else if (v1[i] > v2[j])j++;
	}
	if (v3.empty()) { printf("NULL"); return 0; }
	for (int i = 0; i < v3.size(); i++) {
		if (i == 0)cout << v3[i];
		else cout << " " << v3[i];
	}
    return 0;
}

