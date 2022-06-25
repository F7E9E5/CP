#include <string.h>
#include <iostream>
#define INF 0x3F3F3F3F
using namespace std;

int N, K, M, L;
int pre[13];	/*pre[a] a�� ���� ����*/
int classes[11]; /*class[a] a�б��� ���� ����*/
int cache[11][1 << 12];

/*x�� ���� ��Ʈ ���� ��ȯ*/
int bitCount(int x) {
	if (!x) return 0;
	return __builtin_popcount(x); 
}

/*���� semester�б��̰�, ���� ������� taken���� �־��� ��, ������ �ٳ�� �� �ּ� �б� ��ȯ */
int solve(int semester, int taken) {
	/*K�� �̻��� ������ ���� ���*/
	if (bitCount(taken) >= K) return 0;
	/*���� �бⰡ ���� ���*/
	if (semester == M) return INF;
	
	int& ret = cache[semester][taken];
	if (ret != -1) return ret;
	ret = INF;
	
	/*�̹� �б⿡ ���� ������ ���� �� ���� �������� ���� ������ ���*/
	int canTake = (classes[semester] & ~taken);
	
	/*���� ���� ������ ���� ���� ������� �ɷ�����.*/
	for (int i = 0; i < N; i++) {
		if ((canTake & (1 << i)) && (taken & pre[i]) != pre[i]) {
			canTake &= ~(1 << i);
		}
	}
	
	/*���� �� �ִ� ���� ������ ��� �κ�����(������ ����)�� ��ȸ�Ѵ�.*/
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		if (bitCount(take) > L) continue;
		ret = min(ret, solve(semester + 1, taken | take) + 1);
	}
	ret = min(ret, solve(semester + 1, taken));
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		memset(pre, 0, sizeof(pre));
		memset(cache, -1, sizeof(cache));
		memset(classes, 0, sizeof(classes));
		
		cin >> N >> K >> M >> L;
		
		for (int i = 0; i < N; i++) {
			int R; cin >> R;
			for (int j = 0; j < R; j++) {
				int x; cin >> x; 
				pre[i] |= (1 << x);
			}
		}
		
		for (int i = 0; i < M; i++) {
			int c; cin >> c;
			for (int j = 0; j < c; j++) {
				int x; cin >> x;
				classes[i] |= (1 << x);
			}
		}
		int result = solve(0, 0);
		if (result >= INF) cout << "IMPOSSIBLE\n";
		else cout << result << '\n';
	}	
}

