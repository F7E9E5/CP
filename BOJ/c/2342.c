#include <math.h>
#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int song[100001];
int dp[5][5][100001];

/*Dynamic Programming
dp[a][b][c] -> c��° ������ ���ư�, ���� ���� a��, ������ ���� b�� ���� ���� cost �ּҰ� 
dp[a][b][c] = ���� �� �� �� �ϳ��� ���� ����� ��ģ�ٸ�, cost = 1
			  �� �̿��� ��쿡�� �� ���� ��� ��ġ�� �Űܺ��� �� �� �ּҰ��� ����.
�ʱⰪ�� �ſ� ū ������ �����Ͽ�(���������δ� ����), �������� ���� ���� ���ܵǵ��� �Ѵ�. 
c�� ��ü ����Ƚ���� ��, 20���� ��찡 ���� ���ε�, �� �� �ּҰ��� ���� �ȴ�.*/

int main() {
	int a, N = 1;
	while (1) {
		scanf("%d", &a);
		if (!a) break;
		song[N++] = a;
	}
	
	memset(dp, 0x3F, sizeof(dp));
	dp[0][0][0] = 0;
	dp[song[1]][0][1] = 2;
	dp[0][song[1]][1] = 2;
	
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (j == song[i] || k == song[i]) dp[j][k][i] = MIN(dp[j][k][i], dp[j][k][i - 1] + 1);
				else {
					if (!j) dp[song[i]][k][i] = MIN(dp[song[i]][k][i], dp[j][k][i - 1] + 2);
					else if (abs(j - song[i]) == 1 || abs(j - song[i]) == 3) 
						dp[song[i]][k][i] = MIN(dp[song[i]][k][i], dp[j][k][i - 1] + 3);
					else if (abs(j - song[i]) == 2) 
						dp[song[i]][k][i] = MIN(dp[song[i]][k][i], dp[j][k][i - 1] + 4);

					if (!k) dp[j][song[i]][i] = MIN(dp[j][song[i]][i], dp[j][k][i - 1] + 2);
					else if (abs(k - song[i]) == 1 || abs(k - song[i]) == 3) 
						dp[j][song[i]][i] = MIN(dp[j][song[i]][i], dp[j][k][i - 1] + 3);
					else if (abs(k - song[i]) == 2) 
						dp[j][song[i]][i] = MIN(dp[j][song[i]][i], dp[j][k][i - 1] + 4);
				}
			}
		}
	}
	
	int min = INF;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j || (i != song[N - 1] && j != song[N - 1])) continue;
			min = MIN(min, dp[i][j][N - 1]);
		}
	} 
	printf("%d\n", min);
}

