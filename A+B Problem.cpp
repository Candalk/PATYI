// A+B Problem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
��������
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
		����A��B��С������±꣬�ֱ��Ϊa,b.���û���򷵻�-1

		���磬A="1234.12"   ��a=4
			  B="1234"      ��b=-1
	*/
	a = A.find('.');
	b = B.find('.');
	/*
	�����С���㣬ȥ��
	�����������С������±��Ϊ���ǵĳ���
		���磬A="1234.12"   ��a=4,ȥ��С���㣬A="123412"��a��С����
			  B="1234"      ��b=-1,û��С���㣬��b=4
	*/
	if (a != -1)
		A.erase(a,1);
	else a = A.length();
	if (b != -1)
		B.erase(b,1);
	else b = B.length();
	/*
	����С�����±��ֵ������������
	����A="1212"��B="12"
	�����A="1212"��B="0012"
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
	����A,B�ĳ��Ȳ���С������
	*/

	if (A.length() > B.length())
		B.append( A.length() - B.length(),'0');
	else
		A.append(B.length() - A.length(),'0');
	cout << A <<endl << B << endl;
	/*
	C���ڼ����¼�����kΪC���±꣬yΪ��λ��iΪA��B���±�
	flag���ڱ�ǽ�������Ƿ�С���㣬�����С����ſ���ȥ��ȥû�õ�0
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
	��������н�λ
	*/
	if (y > 0)C[k++] = y + '0';
	int j = 0;
	/*
		�Ѷ����0������
	*/
	if(flag)
	while (C[j] == '0')j++;
	/*
		���ȥ��0�������һ����С���㣬Ҳ���Ե���
	*/
	if (C[j] == '.')j++;
	for(int i=k-1;i>=j;i--)
	 cout << C[i];
    return 0;
}

