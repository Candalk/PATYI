// 二叉排序树指针版.cpp : 定义控制台应用程序的入口点。
//

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

