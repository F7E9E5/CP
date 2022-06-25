#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

/*2533������ �����ظ� ����ϴ� ���� �߰��� ����*/
	
int cache[10002][2], weight[10002];
vector<int> edges[10002], tree[10002], result;

/*���� ���� : �ִ� �������տ� ���ϴ� �������� '��������'���� ���*/ 

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

void reconstruct(int current, bool selected) {
	if (selected) {
		result.push_back(current);
		for (int i : tree[current]) reconstruct(i, false);
	}
	else {
		for (int i : tree[current]) {
			if (solve(i, true) > solve(i, false)) reconstruct(i, true);
			else reconstruct(i, false);
		}
	}	
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
	int tr = solve(1, true), fa = solve(1, false);
	if (tr > fa) {
		cout << tr << '\n';
		reconstruct(1, true);
	}
	else {
		cout << fa << '\n';
		reconstruct(1, false);
	}
	sort(result.begin(), result.end());
	for (int i : result) cout << i << ' ';
	cout << '\n';	
}

