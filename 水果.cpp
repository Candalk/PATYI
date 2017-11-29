// 水果.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
using namespace std;
struct node {
	map<string, int> m;
};
int main()
{
	map<string, struct node> MAP;
	int N, M;
	cin >> N ;
	for (int i = 0; i < N; i++) {
		cin >> M;
		for (int j = 0; j < M; j++) {
			string fruit, location;
			int num;
			cin >> fruit >> location >> num;
			MAP[location].m[fruit] +=num;
		}
		map<string, struct node>::iterator it = MAP.begin();
		while (it != MAP.end()) {
			cout << it->first<<endl;
			map<string, int>::iterator it2 = it->second.m.begin();
			while (it2 != it->second.m.end()) {
				printf("   |----%s(%d)\n", it2->first.c_str(), it2->second);
				it2++;
			}
			it++;
		}
		MAP.clear();
	}
    return 0;
}

