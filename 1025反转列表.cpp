// 1025��ת�б�.cpp : �������̨Ӧ�ó������ڵ㡣
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
	while (P != -1) {//ͳ����Ч�ڵ�ĸ���
		sum++;
		P = L[P].Next;
	}
	P = Start;
	int flag = 0;//flag���ڼ�¼�Ƿ�Ϊ��һ������
	while (P != -1) {
		S.push(L[P]);//�ѽڵ�ѹջ
		n++;
		if (S.size() == K) {//��ջ�еĽڵ�ﵽKʱ�������
			while(S.size()>0){
				tmp=S.top();
				if (flag == 0) {//����ǵ�һ�����
					printf("%05d %d ",tmp.Address,tmp.Data);
					flag = 1;
				}
				else {
					printf("%05d\n%05d %d ", tmp.Address, tmp.Address, tmp.Data);
				}
				S.pop();
			}

			if (sum-n>0&&sum - n < K) {//�ж�ʣ�µĽڵ㻹�ж��٣��������K����ֱ�������
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

