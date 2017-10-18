// L3-005(������ֲ�).cpp : �������̨Ӧ�ó������ڵ㡣
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
	int Id = -1;//���ڼ�¼���������Ͱ�ĺ���
	double Num = -1, Aver = inf;//Num���ڼ�¼��̾��룬Aver���ڼ�¼ƽ������
	for (int index = N + 1; index <= N + M; index++) {//�ֱ��G1��...GM����Dijkstra
		double	minnum = inf, aver = inf,sum=0;
		fill(dis, dis + 1011, inf);//���G[index]�����е�ľ���Ϊinf
		fill(visit, visit + 1011, false);
		for (int i = 1; i <= N + M; i++)//����G[index]�����е�ľ���
			dis[i] = e[i][index];
		dis[index] = 0;


		for (int i = 1; i <= N + M; i++) {
			int u = -1, minn = inf;		//u���ڼ�¼��һ��û���ʹ�����̵Ľڵ㣬minn���ڼ�¼��Сֵ
			for (int j = 1; j <= N + M; j++) {
				if (visit[j] == false && dis[j] < minn) {//���û���ʹ����Ҿ���dis[j]����̾���minn���̣�����u��minn��ֵ
					u = j;								 
					minn = dis[j];
				}
			}

			if (u == -1)break;		//���û�����������ĵ㣬ֹͣ
			visit[u] = true;		//������Ϊ���ʹ�

			for (int v = 1; v <= N + M; v++) {//̽Ѱ��һ����̾��룬
				if (visit[v] == false && dis[v] > dis[u] + e[u][v])
					dis[v] = dis[u] + e[u][v];
			}
		}

		for (int j = 1; j <= N; j++) {//����Сֵ��������ܺ�
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
		if (minnum == -1)//����еľ��볬���������룬��������ѭ��
			continue;

	
		//minnum�Ǳ��ε���Сֵ������˴ε�minnum������һ�ε�Num��na��Num����
		//�����Ǳ�����Сֵ����һ����Сֵ��ȣ�Ҳ����
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