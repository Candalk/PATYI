// 7-7 ����ƥ�䣨25 �֣�.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
��ʱ��û���뵽�����Ŵ����ұߴ����ŵ���������Լ��������Ҫ����ջ�Ƿ�Ϊ�գ���Ϊ�������no���������yes��
 */
#include "stdafx.h"
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string s;
	stack<char> stack;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			stack.push(s[i]);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (!stack.empty()&&(stack.top() == '('&&s[i] == ')'||
				stack.top() == '['&&s[i] == ']'||
				stack.top() == '{'&&s[i] == '}')) 
			{ stack.pop(); continue; }
			else {
				cout << "no";
				return 0;
			}
		}
	}
	if(stack.empty())
	cout << "yes";
	else cout << "no";
    return 0;
}

