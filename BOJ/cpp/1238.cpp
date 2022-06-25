#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define NUM 0x7F7F7F7F
using namespace std;

vector<pair<int, int> > edge[1001];	/*edge[s] = (v, t) s to v costs t*/

/*return cost for s -> v*/
int dijkstra(int s, int v) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	int d[1001];
	memset(d, 0x7F, sizeof(d));
	d[s] = 0;
	q.push(make_pair(d[s], s));
	
	while (!q.empty()) {
		int node = q.top().second;
		int dist = q.top().first;
		if (node == v) break;
		q.pop();
		
		for (auto i : edge[node]) {
			int temp = dist + i.second;
			if (d[i.first] > temp) {
				d[i.first] = temp;
				q.push(make_pair(d[i.first], i.first));
			}
		}
	}
	return d[v];
}

int main() {
	int N, M, X; scanf("%d %d %d", &N, &M, &X);
	for (int i = 0; i < M; i++) {
		int s, v, t; scanf("%d %d %d", &s, &v, &t);
		edge[s].push_back(make_pair(v, t));
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	
	/*�� �л��� ���� ���ͽ�Ʈ�� + �����ϸ� ��� ����
	X���� ���ͽ�Ʈ�� -> �� �ð��� ���ؼ� ��*/
	
	/*X���� ���ͽ�Ʈ�� -> ���� ���� ���� ��ü ��带 ��� �湮*/
	int dX[1001];
	memset(dX, 0x7F, sizeof(dX));
	dX[X] = 0; 
	q.push(make_pair(dX[X], X));
	while (!q.empty()) {
		int node = q.top().second;
		int dist = q.top().first;
		q.pop();
		for (auto i : edge[node]) {
			int temp = dist + i.second;
			if (dX[i.first] > temp) {
				dX[i.first] = temp;
				q.push(make_pair(dX[i.first], i.first));
			}
		}
	}
	
	/*i ��忡�� X���� �Ÿ� ���� �� ��*/
	int max = -1;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		dX[i] += dijkstra(i, X);
		max = max > dX[i] ? max : dX[i];
	}
	printf("%d\n", max);
}

