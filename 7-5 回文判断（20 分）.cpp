// 7-5 回文判断（20 分）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	
	string a,b;
	cin >> a;
	b = a;
	reverse(b.begin(), b.end());
	if ( a==b) {
		printf("YES");
	}
	else printf("NO");
	return 0;
}

