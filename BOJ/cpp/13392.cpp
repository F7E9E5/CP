#include <stdio.h>
#include <iostream>
using namespace std;

/*������ ���ڳ��翡 ���Ͽ� ���� ������ ���� ���� �Ǵ� �������� 2�����̴�.
�̶� ���� ������ ���� � ���ڳ����� ���� ���´� ���� ���ڳ������ ��������
���� Ƚ���� ���� �����ǹǷ�, ���� ������ ���ڳ����� ��ȣ, ������ �������� ����
Ƚ���� ����Ѵ�. �̶�, ���� Ƚ�� % 10���� ����ϸ� �ȴ�. */

int N, cache[10001][11], before[10001], after[10001];

int solve(int current, int turn) {
	if (current == N) return 0;
	
	int& ret = cache[current][turn];
	if (ret != -1) return ret;
	
	int turned = (before[current] + turn) % 10; 
	int toLeft = after[current] - turned;
	if (after[current] < turned) toLeft += 10;
	int toRight = 10 - toLeft;
	
	return ret = min(toLeft + solve(current + 1, (turn + toLeft) % 10), 
	toRight + solve(current + 1, turn));	
}

int main() {
	cin >> N;	
	fill_n(&cache[0][0], 10001 * 11, -1);
	for (int i = 0; i < N; i++) scanf("%1d", &before[i]);
	for (int i = 0; i < N; i++) scanf("%1d", &after[i]);
	cout << solve(0, 0) << '\n';
}

