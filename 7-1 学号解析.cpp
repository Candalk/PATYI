// 7-1 学号解析.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int main() {
	string a;
	cin >> a;
	cout << "year:" << a.substr(0, 4) << endl;
	cout << "department:" << a.substr(4, 2) << endl;
	cout << "class:" << a.substr(6, 2) << endl;

}
