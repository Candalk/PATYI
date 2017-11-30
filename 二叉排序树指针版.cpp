// 二叉排序树指针版.cpp : 定义控制台应用程序的入口点。
//
/*
二叉排序树
提交程序
所有提交历史
提交排行

分数：5
时间限制：1.0s
内存限制：32M
作者：
boyce

题目类型

依次给出n(0<n<100000)个整数，请你以这n个数创建一棵二叉排序树，这棵排序树的根节点为第一个数，并输出其中序遍历和后序遍历。

输入
共两行，第一行为整数n，第二行为n个整数

输出
共两行，第一行为中序遍历，第二行为后序遍历

输入样例
Copy
8
23 45 12 6 7 89 13 47
输出样例
Copy
6 7 12 13 23 45 47 89 
7 6 13 12 47 89 45 23

*/
#include "stdafx.h"
#include<iostream>
using namespace std;
typedef struct node {
	int data;
	struct node *right, *left;
}BitNode,* BitTree;
int flag = 1;
void Mid(BitTree p) {
	if (p == NULL)return;
	Mid(p->right);
	if (flag) {
		printf("%d", p->data);
		flag = 0;
	}
	else printf(" %d",p->data);
	Mid(p->left);
}
void last(BitTree p) {
	if (p == NULL)return;
	last(p->right);
	last(p->left);
	if (flag) {
		printf("%d", p->data);
		flag = 0;
	}
	else printf(" %d", p->data);
}
int main()
{
	BitTree root = NULL;
	BitNode *p, *t, *f;//p用于寻找待插入的节点，t用于记录节点，f表示p的上一节点
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		t = (BitNode *)malloc(sizeof(BitNode));
		t->data = temp;
		t->left = t->right = NULL;
		p = root;
	
		while (p) {
			f = p;
			if (p->data > temp) 
				p=p->right;
			else p = p->left;
		}
		if (root == NULL)root = t;
		else if (f->data > temp)f->right = t;
		else f->left = t;
		
	}
	//cout << root->data;
	Mid(root);
	cout << endl;
	flag = 1;
	last(root);
    return 0;
}

