/*

��Ŀ������
С��ͬѧѧ�����ó���������ת�����쳣���ˡ�С��Ϊ�˲������������������������ѵ����Ŀ����������ĸ��A��Z�����α�ʾ26��1��26�����֡�Ҳ����A=26��B=25...Z=1��������Щ�ַ���������һ��26���Ƶļ�����ʽ�����磨ZZ��26����=��27��10���ơ�

���룺
��һ������N����ʾ����������N���������ݡ���N<1000��

��������N�У�ÿ��һ�����Ȳ�����100���ַ�����

�����
�������(��С����)֮����ַ�����һ��һ����

��������
2
CA
BA
�������
CA
BA
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string s1, string s2) {
	if (s1.size() != s2.size())//����s1,s2���Ȳ�һ�������
		return s1.size() < s2.size();
	else
		return s1 > s2;
}
int main()
{

	int N;
	string S;
	vector<string> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S;
		v.push_back(S);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		cout << v[i] << endl;
	}
    return 0;
}

