#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#define INF 0x3F3F3F3F
using namespace std;

/*������ Ƽ�Ϻ�� ������ ���� ���� ��θ� ã�ƾ� �Ѵ�.
���� �ܼ��� ������δ� ��� �������(0~10000)�� ���ؼ� ���ͽ�Ʈ�� �˰�����
����غ��� ���̴�. �̶� memoization�� �̿��� �ð��� ���� �� ���� ������?
dp[a][b] = a���� b�� ����Ͽ� �ɸ��� �ּ� �ð�
		 = a���� 1~b-1�� ����Ͽ� �ɸ��� �ּ� �ð� �� �ּ� or
		   a ���� ���ñ��� b-k�� ����Ͽ� �ɸ��� �ּ� �ð� + ������->a �ð�
������ ������ ��ε��� ��� Ž���ؾ� �ϱ� ������ �켱���� ť�� ������� �ʾƵ� �� �Ͱ���.

50%���� �ð� �ʰ� -> q�� �ʹ� ���� ���� ť�� ��� �ִ°�?
���� ���� ���ຸ�� �� ���� ������ �־��� ���(dp�� ���� Ȯ��)
�̹� ������ ��� �ߴ��Ѵٴ� ������ ���� ����Ǿ���.
*/

typedef struct {
	int end, price, time;
} edge;

typedef struct {
	int now, nowtime, nowcost;
} city;

int dp[101][10001];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		vector<edge> edges[101];
		int N, M, K; scanf("%d %d %d", &N, &M, &K);
		for (int i = 0; i < K; i++) {
			int u, v, c, d; scanf("%d %d %d %d", &u, &v, &c, &d);
			edges[u].push_back({ v, c, d });
		}

		memset(dp, 0x3F, sizeof(dp));
		dp[1][0] = 0;
		queue<city> q;
		q.push({ 1, 0, 0 });
		while (!q.empty()) {
			city node = q.front(); q.pop();
			if (dp[node.now][node.nowcost] < node.nowtime) continue;

			for (auto i : edges[node.now]) {
				int nextcost = node.nowcost + i.price; 
				if (nextcost > M) continue;
				if (dp[i.end][nextcost] > dp[node.now][node.nowcost] + i.time) {
					dp[i.end][nextcost] = dp[node.now][node.nowcost] + i.time;
					q.push({ i.end, dp[i.end][nextcost], node.nowcost + i.price });

					for (int j = nextcost + 1; j <= M; j++) {
						if (dp[i.end][nextcost] < dp[i.end][j]) 
							dp[i.end][j] = dp[i.end][nextcost];
					}
				}
			}
		}

		if (dp[N][M] == INF) printf("Poor KCM\n");
		else printf("%d\n", dp[N][M]);
	}
}

