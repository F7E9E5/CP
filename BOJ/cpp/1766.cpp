#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
�ڽ��� ������ ���, �ڽ��� ���� ��尡 ���� ���̸� ���� ���� �ͺ��� ���
->priority queue�� ����Ͽ� ����, �ڽ��� ���� ������ ����԰� ���ÿ�
�� ����� �θ���� indegree--, if (!indegree) -> pq.push 
*/

int child[32001] = { 0 };
vector<int> v[32001];
priority_queue<int, vector<int>, greater<int> > q; 

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int A, B; scanf("%d %d", &A, &B);
		v[A].push_back(B);
		child[B]++;	
	}
	for (int i = 1; i <= N; i++) if (!child[i]) q.push(i);
	while (!q.empty()) {
		int node = q.top();
		q.pop();
		for (auto i : v[node]) {
			child[i]--;
			if (!child[i]) q.push(i);
		}
		printf("%d ", node);
	}
}
