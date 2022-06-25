#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

/*������ �� ������� ���� = 2^N, ���� or ���� ����
��� �� ����Ͱ� �ƴ� ������ �� ���� ��尡 ��� �� ����Ϳ��� �Ѵ�.
� ��带 ��Ʈ�� ���, �� ����� ���θ� ���Ѵ�. ���� �� ����ͷ� �Ѵٸ�, ���� ������
�� ����� ���δ� �������. �׷��� �� ����Ͱ� �ƴ϶�� �Ѵٸ�, ���� ��� ��ΰ� �� ����Ͱ�
�Ǿ�� �Ѵ�. �̶� � ����� �� ����� ���θ� �˱� ���� �ʿ��� ���� �ٷ� ���� ����� 
�� ����� ���ζ�� ���� �� �� �ִ�.*/

int cache[2][1000002]; 
vector<int> edges[1000002], tree[1000002];

/*���� ��尡 current�̰�, early�� ������ ��, �ڽ��� ��Ʈ�� �ϴ� ����Ʈ���� �ʿ���
�ּ� �� ������� �� ��ȯ*/
int solve(int current, int early) {
	int& ret = cache[early][current];
	if (ret != -1) return ret;
	
	/*���� ��尡 �� ����Ͷ�� ���� ����� ���´� �������� �ʴ´�.*/
	if (early) {
		ret = 1;
		for (int i : tree[current]) ret += min(solve(i, 1), solve(i, 0));
	}
	/*���� ��尡 �� ����Ͱ� �ƴ϶�� ���� ���� �� ����Ϳ����� �� �� �ִ�.*/
	else {
		ret = 0;
		for (int i : tree[current]) ret += solve(i, 1);
	}
	return ret;
}

bool visit[1000002] = { false };

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
	for (int i = 0; i < N - 1; i++) {
		int u, v; cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	makeTree(1);
	int result = min(solve(1, 1), solve(1, 0));
	cout << result << '\n';
}

