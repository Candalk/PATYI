#include<iostream>
using namespace std;
int main()
{
	int T, K;
	int n1, b, t, n2;
	cin >> T >> K;
	for (int i = 0; i < K; i++) {
		cin >> n1 >> b >> t >> n2;	
		 if (T == 0) {
			printf("Game Over.");
			return 0;
		}
		 if(t > T) {
			 printf("Not enough tokens.  Total = %d.\n", T);
			 continue;
		 }
		if (b == 0&&n1 > n2||b == 1&&n1 < n2) {
			T = T + t;
			printf("Win %d!  Total = %d.\n", t,T);
		}
		else {//Èç¹ûÊäÁË	
			T = T - t;
			printf("Lose %d.  Total = %d.\n",t, T);
		}
	}
    return 0;
}

