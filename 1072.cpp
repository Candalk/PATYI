#include<iostream>
#include<string>
using namespace std;
int main()
{
  int N, M, flag[10000] = { 0 }, K, Num,stu=0,total=0;
  string name;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> K;
    flag[K] = 1;
  }

  for (int i = 0; i < N; i++) {
    cin >> name;
    cin >> K;
    int flag1 = 0;
    for (int i = 0; i < K; i++) {
      cin >> Num;
      if (flag[Num] == 1) {
        total++;
        if (flag1 == 0)
          cout << name << ":";
        printf(" %0.4d", Num);
        flag1++;
      }
    }
    if (flag1 != 0) { stu++; cout << endl; }
  }
  cout << stu << " " << total;
  return 0;
}