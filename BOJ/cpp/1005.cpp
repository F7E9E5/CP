#include <stdio.h>
#include <string.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 
 
/*�ǹ� a�� ���� ���� �� �ڽ� �ǹ����� ��� ����� �Ѵ�.
�� �ǹ� a�� ���� �� �ɸ��� �ּ� �ð�
= MAX(�ǹ� a�� �ڽĵ��� ���µ� �ɸ��� �ּ� �ð�) + a�� ���� �ð�*/

/*�Լ��� ���� Topdown ������� �����غ������� ȣ���� �ʹ� ���� �Ͼ �޸� �ʰ� �߻�*/
/*�ణ�� ����ȭ�� ���� ����Ǿ���.*/

int minT[1001];
int time[1001]; /*�ǹ��� ���� �� �ҿ�Ǵ� �ð�*/
int childNum[1001];
int child[1001][1001]; /*child[k] �ǹ� k�� ���� �� �ʿ��� �ǹ���*/

int solve(int W) {
	if (minT[W] != -1) return minT[W];
	if (!childNum[W]) return minT[W] = time[W];
	int min = -1;
	for (int i = 0; i < childNum[W]; i++) {
		if (minT[child[W][i]] != -1) min = MAX(min, time[W] + minT[child[W][i]]);
		else min = MAX(min, time[W] + solve(child[W][i]));
	}
	return minT[W] = min;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int N, K, W; scanf("%d %d", &N, &K);
		memset(minT, -1, sizeof(minT));
		memset(childNum, 0, sizeof(childNum));
		for (int j = 1; j <= N; j++) scanf("%d", &time[j]);
		for (int j = 0; j < K; j++) {
			int X, Y; scanf("%d %d", &X, &Y);
			child[Y][childNum[Y]++] = X;
		}
		scanf("%d", &W);
		printf("%d\n", solve(W));	
	}
}

