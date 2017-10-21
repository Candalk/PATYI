// A+B Problem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
测试数据
	A		B		C
	1.9	   0.1		2
	0.1	   1.9      1
	1.23   2.1     3.33
	3	   4.0     7
	89	   11      100
	13.072 12.100  25.172

*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	string A, B;
	int a, b;
	cin >> A >> B ;
	/*
		查找A和B中小数点的下标，分别记为a,b.如果没有则返回-1

		例如，A="1234.12"   则a=4
			  B="1234"      则b=-1
	*/
	a = A.find('.');
	b = B.find('.');
	/*
	如果有小数点，去掉
	如果是整数则将小数点的下标记为他们的长度
		例如，A="1234.12"   则a=4,去掉小数点，A="123412"，a大小不变
			  B="1234"      则b=-1,没有小数点，则b=4
	*/
	if (a != -1)
		A.erase(a,1);
	else a = A.length();
	if (b != -1)
		B.erase(b,1);
	else b = B.length();
	/*
	根据小数点下标的值补齐整数部分
	例如A="1212"，B="12"
	补齐后，A="1212"，B="0012"
	*/
	if (a > b) {
		string C(a - b,'0');
		B = C + B;
		b = a;
	}
	else {
		string C(b - a, '0');
		A = C + A;
		a = b;
	}
	/*
	根据A,B的长度补齐小数部分
	*/

	if (A.length() > B.length())
		B.append( A.length() - B.length(),'0');
	else
		A.append(B.length() - A.length(),'0');
	cout << A <<endl << B << endl;
	/*
	C用于计算记录结果，k为C的下标，y为进位，i为A和B的下标
	flag用于标记结果里面是否小数点，如果有小数点才可以去舍去没用的0
	*/
	char C[401]="";
	int i = A.length()-1,k=0,y=0;
	bool flag = false;
	while (i >= 0) {
		C[k] = (y + A[i] + B[i] - 2 * '0') % 10+'0';
		y = (y + A[i] + B[i] - 2 * '0') / 10;
		k++;
		if (k == A.length() - a ) {
			C[k] = '.';
			k++;
			flag = true;
		}
		i--;
	}
	/*
	考虑最后还有进位
	*/
	if (y > 0)C[k++] = y + '0';
	int j = 0;
	/*
		把多余的0都忽略
	*/
	if(flag)
	while (C[j] == '0')j++;
	/*
		如果去完0后发现最后一个是小数点，也忽略掉。
	*/
	if (C[j] == '.')j++;
	for(int i=k-1;i>=j;i--)
	 cout << C[i];
    return 0;
}

