#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*Topological Sorting
Indegree�� ���� 0�� ������ ������ ���� ���� ����Ѵ�.
����� ����� Outdegree�� Ž���Ͽ� �� ������ Indegree�� ���δ�. 
Indegree�� 0�̶�� ����� ���鿡 ���Խ�Ų��. 

������ ���ϴ� ���� �Ұ����� ��쿡 ���� �Ǵ��� �ʿ��ϴ�.
�׷������� ����Ŭ�� �����ϴ� ���, �� ����� ����� ���� N�� ������ �� 0�� ����Ѵ�. 
*/

queue<int> q;
int Indegree[1001] = { 0 };
vector<int> answer, Outdegree[1001];

int main() {
	int N, M, num = 0; scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int num; scanf("%d", &num);
		int a, b; scanf("%d", &a);
		for (int j = 0; j < num - 1; j++) {
			scanf("%d", &b);
			Outdegree[a].push_back(b);
			Indegree[b]++;
			a = b; 
		}
	}
	
	for (int i = 1; i <= N; i++) if (!Indegree[i]) q.push(i);
	
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (auto i : Outdegree[t]) {
			Indegree[i]--;
			if (!Indegree[i]) q.push(i);
		}
		num++; 
		answer.push_back(t);
	}
	
	if (num != N) printf("0\n");
	else for (auto i : answer) printf("%d\n", i);
}

