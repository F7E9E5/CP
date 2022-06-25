#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int num;
int team[101];
bool visit[101] = { false };
int teamBest[101];
int teamTime[101];
vector<int> edges[101];

void DFS(int S) {
	team[S] = num;
	visit[S] = true;
	
	for (auto i : edges[S]) {
		if (!visit[i]) DFS(i);
	}
}

/*s�� s�� ���� ����ȸ�� ��ǥ�� �Ǿ��� ��, �ǻ����޽ð��� �ִ� ���ϰ�, �� ����ȸ�� �ǻ����޽ð��� ��*/
void BFS(int S) {
	queue<pair<int, int> > q;
	bool vis[101] = { false };
	q.push({ S, 0 });
	vis[S] = true;
	
	int maxTime = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if (time > maxTime) {
			maxTime = time;
		}
		
		for (auto i : edges[now]) {
			if (!vis[i]) {
				vis[i] = true;
				q.push({ i, time + 1 });
			}
		}
	}
	
	if (teamTime[team[S]] > maxTime) {
		teamBest[team[S]] = S;
		teamTime[team[S]] = maxTime;
	}
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	memset(teamTime, 0x3F, sizeof(teamTime));
	
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	num = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			DFS(i);
			num++;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		BFS(i);
	}
	
	cout << num << '\n';
	vector<int> result;
	for (int i = 0; i < num; i++) {
		result.push_back(teamBest[i]);
	}
	sort(result.begin(), result.end());
	for (auto i : result) {
		cout << i << '\n';
	}
}

