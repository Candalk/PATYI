// aba.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
char s[5010];
int main()
{

	while (scanf("%s", s) != EOF) {

		int len = strlen(s) - 1,num = 0, l, r;
		for (int i = 0; i <= len; ++i, ++num) {

			for (l=i-1,r= i+1; l>=0&&r<=len&&s[l] == s[r]; --l, ++r, ++num)
				;
			for (l = i, r = i + 1; l >= 0 && r <= len&&s[l] == s[r]; --l, ++r, ++num)
				;
		}
		printf("%d\n", num);
	}
	return 0;
}

