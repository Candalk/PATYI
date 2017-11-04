// 7-2 银行业务队列简单模拟.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N,temp;
	cin >> N;
	vector<int> A, B;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp % 2)
			A.push_back(temp);
		else B.push_back(temp);
	}
	if (N == 1) { cout << temp; return 0; }
	int i = 0, j = 0,flag=1;
	while (i < A.size()-1 && j < B.size()) {
		if (flag) {
			printf("%d", A[i++]);
			printf(" %d", A[i++]);
			printf(" %d", B[j++]);
			flag = 0;
		}
		printf(" %d", A[i++]);
		printf(" %d", A[i++]);
		printf(" %d", B[j++]);
	}
	while(i<A.size())
		printf(" %d", A[i++]);
	while(j<B.size())
		printf(" %d", B[j++]);
    return 0;
}

