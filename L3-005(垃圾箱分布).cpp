// L3-005(垃圾箱分布).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;
int e[1011][1011];
int dis[1011];
bool visit[1011];
const int inf = 9999999;
int N, M, K, DS, dist;

int main()
{
	string P1, P2;
	fill(e[0], e[0] + 1011 * 1011, inf);

	cin >> N >> M >> K >> DS;
	for (int i = 0; i < K; i++) {
		int m, n;
		cin >> P1 >> P2 >> dist;
		if (P1[0] == 'G') {
			m = N + stoi(P1.substr(1));
		}
		else {
			m = stoi(P1);
		}
		if (P2[0] == 'G') {
			n = N + stoi(P2.substr(1));
		}
		else {
			n = stoi(P2);
		}
		//printf("m = %d,n = %d,dis = %d\n", m, n, dist);
		e[m][n] = e[n][m] = dist;
	}
	int Id = -1;//用于记录最合适垃圾桶的号码
	double Num = -1, Aver = inf;//Num用于记录最短距离，Aver用于记录平均距离
	for (int index = N + 1; index <= N + M; index++) {//分别对G1，...GM进行Dijkstra
		double	minnum = inf, aver = inf,sum=0;
		fill(dis, dis + 1011, inf);//标记G[index]到所有点的距离为inf
		fill(visit, visit + 1011, false);
		for (int i = 1; i <= N + M; i++)//加上G[index]到所有点的距离
			dis[i] = e[i][index];
		dis[index] = 0;


		for (int i = 1; i <= N + M; i++) {
			int u = -1, minn = inf;		//u用于记录下一个没访问过的最短的节点，minn用于记录最小值
			for (int j = 1; j <= N + M; j++) {
				if (visit[j] == false && dis[j] < minn) {//如果没访问过，且距离dis[j]比最短距离minn还短，跟新u和minn的值
					u = j;								 
					minn = dis[j];
				}
			}

			if (u == -1)break;		//如果没有满足条件的点，停止
			visit[u] = true;		//否则标记为访问过

			for (int v = 1; v <= N + M; v++) {//探寻下一个最短距离，
				if (visit[v] == false && dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}

		for (int j = 1; j <= N; j++) {//找最小值并求距离总和
			if (dis[j] > DS) {
				minnum = -1;
				break;
			}
			if (minnum > dis[j])
				minnum = dis[j];
			sum += dis[j];
			//printf("dis[%d] = %d, ", j, dis[j]);
		}
		aver = sum / N;
		//printf("%lf", aver);
		//cout << endl;
		if (minnum == -1)//如果有的距离超过了最大距离，跳过本次循环
			continue;

	
		//minnum是本次的最小值，如果此次的minnum大于上一次的Num，na将Num换掉
		//或者是本次最小值和上一次最小值相等，也更新
		if (minnum > Num||(minnum == Num&&Aver > aver)) {
			//printf("Id = %d Num = %d Aver = %d\n", Id, Num, Aver);
			Id = index;
			Num = minnum;
			Aver = aver;
			//printf("Id2 = %d Num2 = %d Aver2 = %d\n", Id, Num, Aver);
		}
			
			
	}
	if (Id == -1) {
		printf("No Solution");
	}
	else {
		cout <<"G"<< Id-N << endl;
		printf("%0.1f %0.1f", Num, Aver);
	}
}