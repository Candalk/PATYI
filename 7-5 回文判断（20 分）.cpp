// 7-5 �����жϣ�20 �֣�.cpp : �������̨Ӧ�ó������ڵ㡣
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

