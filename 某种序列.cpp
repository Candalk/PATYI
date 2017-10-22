/*
某种序列
时间限制：3000 ms  |  内存限制：65535 KB 
描述 
数列A满足An = An-1 + An-2 + An-3, n >= 3 
编写程序，给定A0, A1 和 A2, 计算A99
输入
输入包含多行数据 
每行数据包含3个整数A0, A1, A2 (0 <= A0, A1, A2 <= 100000000) 
数据以EOF结束
输出
对于输入的每一行输出A99的值
样例输入
1 1 1
样例输出
69087442470169316923566147
*/
#include<iostream>
#include<string>
using namespace std;
string Add(string A1,string A2) {

	int a1 = A1.length(), a2 = A2.length();
	/*
	短的的数在前面补零
	*/
	if (a1 < a2) {
		string C(a2 - a1, '0');
		A1 = C + A1;
	}
	else {
		string C(a1 - a2, '0');
		A2 = C + A2;
	}
	/*
	这一部分用于计算A1+A2的和，并结果放于C中
	i为A1，A2的下标，从个位数开始计算，k为C的下标。
	*/
	char C[400]="";
	int i = A1.length() - 1, k = 0, y = 0;
	while (i >= 0) {
		C[k] = (y + A1[i] + A2[i] - 2 * '0') % 10 + '0';
		y = (y + A1[i] + A2[i] - 2 * '0') / 10;
		k++;
		i--;
	}
	/*
	考虑最后还有进位
	*/
	if (y > 0)C[k++] = y + '0';
	string S = C;
	//将结果反转
	reverse(S.begin(), S.end());
	return S;
}
int main()
{
	string A[3],tmp1,Sum;
	int k=3;
	cin >> A[0] >> A[1] >> A[2];
	while (k<=99) {
		tmp1=Add(A[0], A[1]);
		Sum=Add(tmp1,A[2]);
		A[0] = A[1];
		A[1] = A[2];
		A[2] = Sum;
		k++;
	}
	cout << Sum << endl;
    return 0;
}

