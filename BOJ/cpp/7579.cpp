#include <iostream>
#include <string.h>
#include <algorithm>
#define INF 0x3F3F3F3F
using namespace std;

/*� �۵��� ��Ȱ��ȭ���Ѽ� M �̻��� �޸𸮸� Ȯ���ؾ� �ϴ� ��, �̶� ��Ȱ��ȭ��Ű��
�۵��� ��� ���� �ּ�ȭ���Ѷ�. ������ ��� ����� �� 2^N, �� �ۿ� ���� �������� on | off�̴�.
� �޸� ���� Ȯ���ϴ� �� ��� �ּ� ����� �˾Ƴ��� �ϴµ�, �̶� �޸��� ������ �ʹ�
ũ�� ������ �޸� �߽��� �ƴ� ��� �߽����� �ذ��ؾ� �Ѵ�. � ��� c�� ������ �ִ� �޸��� 
���� �ʿ��� �޸� ������ ũ�ų� ���ٸ� �� ��� c�� �ּ� ����̴�.*/

int N, c[101], m[101];
int cache[101][10001];

/*current���� ����ؼ� cost�� ������ �ִ� �޸𸮰� ��ȯ*/
int solve(int current, int cost) {
	if (current == N) return 0; 
	
	int& ret = cache[current][cost];
	if (ret != -1) return ret;
		
	ret = max(0, solve(current + 1, cost));
	if (cost >= c[current]) ret = max(ret, solve(current + 1, cost - c[current]) + m[current]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int M, result;	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> m[i];
	for (int i = 0; i < N; i++) cin >> c[i];
	
	for (int i = 0; i < 10001; i++) {
		if (solve(0, i) >= M ) { result = i; break; }
	}	
	cout << result << '\n'; 
}

