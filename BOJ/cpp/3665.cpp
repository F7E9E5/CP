#include <stdio.h>
#include <queue>
using namespace std;

/*Topological Sorting 
�� 1, 2, 3, 4�� ���� �� �� ���� ��ȣ�� ����� ����ߴٰ� ����.
�� 1�� �� 2, 3, 4���� �켱�ϰ�, �� 2�� �� 3, 4���� �켱�ϰ�, �� 3�� �� 4���� �켱�Ѵ�.
���� �̰��� Directed Graph�� Topological sorting�Ѱ����� �� �� �ִ�.
���� �� ������ ��� ��ȭ�� �� ��带 �ִ� ������ ������ �ٲ� ������ �� �� �ִ�.

������ ������ �� ������ ����� ���� ��� �� �������� ������ �������� ��,
������ �ٲ� �������� �������ش�. �� �� Topological Sorting�Ѵ�.

Ȯ���� ������ ���� �� ���� ��� = ��� �ĺ��� ���� ���� ��� 
�ϰ����� ���� ��� = ����Ŭ�� ����� ���*/

/*���� ���� -> ������ ������ �ٲٴ� �κп��� ��Ÿ*/

/*�� �� �̻��� ��尡 �ĺ��� �Ǵ� ���� �������� ����
1. ������ ��忡 ���ؼ� Indegree ���� �������� ���� �迭�� �����Ѵ�. (������ ���� ������ 
n-1, n-2, n-3..., �̹� ����� ���� �����ϰ�) ���� ������ ������ �ٲٴ� �������� �� ������
�����ȴ�. (������ �ٲ� ��� ���� ��� ����) 
2. ������ ���ึ�� ��� ����(����� ���, ���� ��� ����)�� Indegree�� �׻� 1�� �پ���. 
�ϳ��� �������� �ٸ� �������� ���� edge�� �׻� �ϳ��̱� �����̴�. 
=> ���� ���ÿ� 0�� �Ǵ� ��尡 �� �� �̻��� �� ����.

���� ���������� Ȯ��ġ�ʴ� �Ф� 
�׷��� ?�� �����ϰ� �����ص� ������ ���� ���� ���� �����ε� �ϴ�.*/

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m;
		queue<int> q;
		bool edge[501][501] = { false }; 
		int Indegree[501] = { 0 }, result[501], count = 0;
		int rank[501];	/*rank[a] = b -> �۳⿡ b���� a���� ��*/ 
		
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &rank[i]);
		
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) edge[rank[j]][rank[i]] = true;
			Indegree[rank[i]] = n - i;
		}
		
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			if (edge[a][b]) {
				edge[a][b] = false; edge[b][a] = true;
				Indegree[a]++; Indegree[b]--;
			}
			else {
				edge[b][a] = false; edge[a][b] = true;
				Indegree[b]++; Indegree[a]--;
			}
		} 
		
		for (int i = 1; i <= n; i++) if (!Indegree[i]) q.push(i);
		while (!q.empty()) {
			int t = q.front(); q.pop();
			for (int i = 1; i <= n; i++) {
				if (edge[t][i]) {
					Indegree[i]--;
					if (!Indegree[i]) q.push(i);
				}
			}
			result[count++] = t;
		}
		
		if (count < n) printf("IMPOSSIBLE\n");
		else {
			for (int i = n - 1; i >= 0; i--) printf("%d ", result[i]);
			printf("\n");
		}
	}
}

