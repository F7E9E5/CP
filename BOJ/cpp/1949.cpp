#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int cache[10002][2], weight[10002];
vector<int> edges[10002], tree[10002];

/*���� ��尡 current�̰�, selected�� ������ ��, �ڽ��� ��Ʈ�� �ϴ� ����Ʈ����
�ִ� �������� ũ�� ��ȯ*/
int solve(int current, bool selected) {
	int& ret = cache[current][selected];
	if (ret != -1) return ret;
	
	if (selected) {
		ret = weight[current];
		for (int i : tree[current]) ret += solve(i, false);
	}
	else {
		ret = 0;
		for (int i : tree[current]) ret += max(solve(i, true), solve(i, false));
	}
	return ret;
}

bool visit[10002] = { false };

/*�ܹ��� Ʈ��, �θ� -> �ڽ�*/
void makeTree(int root) {
	visit[root] = true;
	for (int i : edges[root]) {
		if (visit[i]) continue;
		tree[root].push_back(i);
		makeTree(i);
	}
} 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> weight[i];
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	makeTree(1);
	int result = max(solve(1, true), solve(1, false));
	cout << result << '\n';
}

