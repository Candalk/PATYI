// 7-7 括号匹配（25 分）.cpp : 定义控制台应用程序的入口点。
//
/*
当时是没有想到左括号大于右边大括号的情况，所以计算结束后要看看栈是否为空，不为空则输出no，否则输出yes。
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

