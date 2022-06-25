#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool vis[10001] = { false };
int dis[10001] = { 0 };
vector<pair<int, int> > edge[10001];
/*v[i] = (k, w) -> i��° ������ ��������,  k�� ���ϰ� ����ġ�� w�̴�.*/

void DFS(int V) {
	vis[V] = true;
	for (auto i : edge[V]) {
		int k = i.first;
		int w = i.second;
		if (!vis[k]) {
			dis[k] += dis[V] + w;
			DFS(k);
		}
	}
}

int main() {
	int V; scanf("%d", &V);
	for (int i = 0; i < V - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back(make_pair(b, c));
		edge[b].push_back(make_pair(a, c));
	}
	
	int max = 1; dis[1] = 0; DFS(1);
	for (int i = 2; i <= V; i++) max = dis[max] > dis[i] ? max : i;
	memset(dis, 0, sizeof(int) * 10001);
	memset(vis, false, sizeof(bool) * 10001);
	DFS(max);
	sort(dis + 1, dis + V + 1);
	printf("%d\n", dis[V]);
}

