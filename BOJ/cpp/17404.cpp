#include <stdio.h>
#include <algorithm>
#define INF 0x3F7F7F7F
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

/*dp[a][b][c]�� ����
a�� �����ϸ鼭, c��° ���� b�� ĥ���� ���� �ּ� ���
MIN(dp[a][k][c - 1] + price[b][c])�� ���Ѵ�. (k != b)
������ ���� �����Ѵ�.
*/

/*0->R, 1->G, 2->B*/
int price[3][1001];
int dp[3][3][1001] = { 0 };

int main() {
	int N, min = INF; scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d %d %d", &price[0][i], &price[1][i], &price[2][i]);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) dp[i][j][1] = INF;
			else dp[i][j][1] = price[i][1]; 
		}
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			dp[j][0][i] = price[0][i] + MIN(dp[j][1][i - 1], dp[j][2][i - 1]);
			dp[j][1][i] = price[1][i] + MIN(dp[j][2][i - 1], dp[j][0][i - 1]);
			dp[j][2][i] = price[2][i] + MIN(dp[j][0][i - 1], dp[j][1][i - 1]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != j) min = MIN(min, dp[i][j][N]);
		}
	}
	printf("%d\n", min);
}

