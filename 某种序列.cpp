/*
ĳ������
ʱ�����ƣ�3000 ms  |  �ڴ����ƣ�65535 KB 
���� 
����A����An = An-1 + An-2 + An-3, n >= 3 
��д���򣬸���A0, A1 �� A2, ����A99
����
��������������� 
ÿ�����ݰ���3������A0, A1, A2 (0 <= A0, A1, A2 <= 100000000) 
������EOF����
���
���������ÿһ�����A99��ֵ
��������
1 1 1
�������
69087442470169316923566147
*/
#include<iostream>
#include<string>
using namespace std;
string Add(string A1,string A2) {

	int a1 = A1.length(), a2 = A2.length();
	/*
	�̵ĵ�����ǰ�油��
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
	��һ�������ڼ���A1+A2�ĺͣ����������C��
	iΪA1��A2���±꣬�Ӹ�λ����ʼ���㣬kΪC���±ꡣ
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
	��������н�λ
	*/
	if (y > 0)C[k++] = y + '0';
	string S = C;
	//�������ת
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

