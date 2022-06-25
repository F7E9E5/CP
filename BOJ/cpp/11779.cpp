#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 1001
#define INF 1000000000

using namespace std;

int main() {
	int N, M; scanf("%d %d", &N, &M);
	int d[SIZE], S, V, pie[SIZE]; /*pie = ������ �湮�� ���*/
	vector<pair<int, int> > edge[SIZE]; //edge[a] = (b, c) => a->b costs c 
	for (int i = 0; i < M; i++) {
		int s, v, w; scanf("%d %d %d", &s, &v, &w);
		edge[s].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= N; i++) d[i] = INF;
	scanf("%d %d", &S, &V); /*go S to V*/
	
	/*priority queue which maintain q.top.first to min distance*/
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	
	d[S] = 0, pie[S] = -1; 
	q.push(make_pair(d[S], S)); 
	while (!q.empty()) {
		int node = q.top().second; /*extract min*/
		int dist = q.top().first; /*distance of start node to current node*/
		q.pop();
		if (node == V) break;
;		for (auto i : edge[node]) { /*for all outdegree of current node*/
			if (d[i.first] > dist + i.second) {
				d[i.first] = dist + i.second; /*relaxation*/
				q.push(make_pair(d[i.first], i.first));
				/*�ڽ��� ���������� relax�� ��尡 pie�̴�.*/
				pie[i.first] = node;
			}
		}
	}
	
	printf("%d\n", d[V]);
	vector<int> result;
	result.push_back(V);
	int num = 1;
	while (pie[V] != -1) {
		result.push_back(pie[V]);
		V = pie[V]; 
		num++;
	}
	printf("%d\n", num);
    reverse(result.begin(), result.end());
    for (auto i : result) printf("%d ", i);
}

