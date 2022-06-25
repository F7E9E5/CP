#include <iostream>
#include <string.h>
#include <algorithm>
#define NEGINF -987654321
using namespace std;

/*�κ��� �������ε� �̵��� �� �ֱ� ������ �ܼ��� 2���� �迭�� cache�� ������ �� ����.
���� ��� �������� ���ٰ� �Ʒ��� �� ĭ ���ٰ� �ٽ� ���������� ���ƿ��� ���� �ٷ� �� ĭ ��������
�ͺ��� ��� ��ġ�� Ŭ �� �ִ�. �׷��� cache�� 2�������� �����ϸ� �׷��� ��츦 ����� �� ����.*/

int dy[3] = { 0, 1, 0 };
int dx[3] = { -1, 0, 1 };

int N, M;
bool visit[1002][1002] = { false };
int map[1002][1002], cache[1002][1002][3];

bool inRange(int y, int x) { return (y > 0 && y <= N && x > 0 && x <= M); }

/*(y, x)���� (N, M)���� ���� �� ���� �� �ִ� �ִ� ��ġ ��ȯ*/
int solve(int y, int x, int dir) {
	if (y == N && x == M) return map[y][x];
	
	int& ret = cache[y][x][dir];
	if (ret != NEGINF) return ret;
	
	for (int i = 0; i < 3; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!inRange(ny, nx)) continue;
		if (!visit[ny][nx]) {
			visit[ny][nx] = true;
			ret = max(ret, solve(ny, nx, i) + map[y][x]);
			visit[ny][nx] = false;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	fill(&cache[0][0][0], &cache[0][0][0] + 1002 * 1002 * 3 + 1, NEGINF);	
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	visit[1][1] = true;
	cout << solve(1, 1, 0) << '\n';	
}

