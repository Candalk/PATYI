// 7-4 最长连续递增子序列（20 分）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,i,l,j,max=-1;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	
	l = 0; j = 0; max = 1;
	for ( i = 1; i < n; i++) {
		if (v[i] > v[i-1]) {
			continue;
		}
		else if(i-j>max){
			max = i-j;
			l = j;
			j = i;
		}
		else {
			j = i;

		}
	}
	if(i - j>max) {
		max = i - j;
		l = j;
		j = i;
	}
	int flag = 1;
	for (int i = l; i < l+max; i++) {
		if (flag)
			printf("%d", v[i]);
		else
			printf(" %d", v[i]);
		flag = 0;
	}
    return 0;
}

