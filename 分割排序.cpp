/*
分割排序


题目类型

输入一行数字，如果我们把这行数字中的‘5’都看成空格，那么就得到一行用空格分割的若干非负整数（可能有些整数以‘0’开头，这些头部的‘0’应该被忽略掉，除非这个整数就是由若干个‘0’组成的，这时这个整数就是0）。
你的任务是：对这些分割得到的整数，依从小到大的顺序排序输出。

输入
输入包含多组测试数据。每组输入数据只有一行数字（数字之间没有空格），这行数字的长度不大于1000。
输入数据保证：分割得到的非负整数不会大于100000000，输入数据不可能全由‘5’组成。

输出
对于每个测试用例，输出分割得到的整数排序的结果，相邻的两个整数之间用一个空格分开，每组输出占一行。(每行末尾不能有空格)

输入样例
Copy
0051231232050775
输出样例
Copy
0 77 12312320


日了够了一样的题目，错在哪了呢？
1.人家是多组数据，所以要用scanf("%s",s)!=EOF
2.如何判断结尾，因为是字符串，本题情况特殊，阴差阳错的就是不对，
所以要用两个条件去限制，字符串结尾为5，还要用字符穿的长度去限制。
*/
#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	char s[1001];
	while(scanf("%s",s)!=EOF){
		cout<<s<<endl;
		vector<long long> v;
		int len=strlen(s);
		s[len]='5';
		long long a=0;
		for(int i=0;i<=len;i++){
			if(s[i]!='5')a=a*10+s[i]-'0';
			else {
				if(i-1>=0&&s[i-1]!='5'){
					v.push_back(a);
					a=0;
				}
			}
		}
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++){
			if(i==0)cout<<v[i];
			else cout<<" "<<v[i];
		}
		cout<<endl;
	}	
}
