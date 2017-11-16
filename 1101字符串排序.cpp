/*

题目描述：
小乐同学学会了用程序做进制转换，异常高兴。小鹏为了不让他骄傲自满，决定出道难点的题目考考他。字母集A到Z，依次表示26到1，26个数字。也就是A=26，B=25...Z=1。他用这些字符来构建了一个26进制的计数方式。比如（ZZ）26进制=（27）10进制。

输入：
第一行数字N，表示接下来会有N行输入数据。（N<1000）

接下来的N行，每行一个长度不超过100的字符串。

输出：
输出排序(从小到大)之后的字符串，一行一个。

样例输入
2
CA
BA
样例输出
CA
BA
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string s1, string s2) {
	if (s1.size() != s2.size())//考虑s1,s2长度不一样的情况
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

