// 1025反转列表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<stack>
using namespace std;
struct node {
	int Address,Data, Next;
}L[100001],tmp;
int main()
{
	int Start,N, K,n=0,sum=0;
	int Address, Data, Next,P;
	stack<struct node> S;
	cin >> Start >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> Address >> Data >> Next;
		L[Address].Address = Address;
		L[Address].Data = Data;
		L[Address].Next = Next;
	}

	P = Start;
	while (P != -1) {//统计有效节点的个数
		sum++;
		P = L[P].Next;
	}
	P = Start;
	int flag = 0;//flag用于记录是否为第一次输入
	while (P != -1) {
		S.push(L[P]);//把节点压栈
		n++;
		if (S.size() == K) {//当栈中的节点达到K时，输出来
			while(S.size()>0){
				tmp=S.top();
				if (flag == 0) {//如果是第一次输出
					printf("%05d %d ",tmp.Address,tmp.Data);
					flag = 1;
				}
				else {
					printf("%05d\n%05d %d ", tmp.Address, tmp.Address, tmp.Data);
				}
				S.pop();
			}

			if (sum-n>0&&sum - n < K) {//判断剩下的节点还有多少，如果不足K个，直接输出来
				P = L[P].Next;
				while (P != -1) {
					printf("%05d\n%05d %d ", P, P, L[P].Data);
					P = L[P].Next;
				}
				break;
			}
		}
		P = L[P].Next;
	}
	printf("-1");
    return 0;
}

