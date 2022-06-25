#include <stdio.h>
#include <queue>
#define min(a, b) MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

typedef struct {
	int row;
	int col;
	bool chance;
} node;

int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };
int map[1001][1001];
int vis[2][1001][1001] = { 0 };

int main() {
	int N, M; scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
	/*BFS�� ��θ� Ž���Ѵ�. try ����ü�� �����Ͽ� ���� ����� ��ǥ�� ��ġ,
	�� �μ��� ��ȸ, �̵� �Ÿ��� ��´�. �� �μ����� ������ �ֱ� ������ Ž���� ���ǰ� �ʿ��ϴ�.
	������ �湮 ����� �ִٰ� �ؼ� ����ġ�� �ȵȴ�. ���� �湮 ����� pair�� �����ϴµ�, 
	�� ������ �� �μ��� ��ȸ�� ������ �� �湮�ϴ� ���̰�, �������� �� �μ��� ��ȸ�� ������ �湮�ϴ� ���̴�.*/
	
	/*vis[0]�� �μ��� ��ȸ�� ������ ��, vis[1]�� �μ��� ��ȸ�� ���� ä�� �湮*/
	vis[1][0][0] = 1;	
	queue<node> q;
	node start = { 0, 0, true };
	q.push(start);
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int trow = cur.row + rdi[i];
			int tcol = cur.col + cdi[i];
			if (trow >= 0 && trow < N && tcol >= 0 && tcol < M) {
				if (cur.chance) {
					if (!map[trow][tcol] && !vis[1][trow][tcol]) {
						vis[1][trow][tcol] = vis[1][cur.row][cur.col] + 1;
						node temp = { trow, tcol, true };
						q.push(temp);
					}
					else if (map[trow][tcol] && !vis[0][trow][tcol]) {
						vis[0][trow][tcol] = vis[1][cur.row][cur.col] + 1;
						node temp = { trow, tcol, false };
						q.push(temp); 
					}
				}
				else {
					if (!map[trow][tcol] && !vis[0][trow][tcol]) {
							vis[0][trow][tcol] = vis[0][cur.row][cur.col] + 1;
							node temp = { trow, tcol, false };
							q.push(temp);
					}
				}
			}
		}
	}
	int a = vis[0][N - 1][M - 1], b = vis[1][N - 1][M - 1];
	if (a && b) printf("%d\n", min(a, b));
	else if (!a && b) printf("%d\n", b);
	else if (a && !b) printf("%d\n", a);
	else printf("-1\n");
}

