#include <stdio.h>
#define NUM 1000000000

/*Dynamic Programming
dp[a][b] -> a��° ���ڰ� b�� ������ ��� ���� ����
�� ������ 0~9���� ���ڰ� �ѹ��� �����ߴ��� �����ؾ� �Ѵ�.
�ٽ� ���� �Ȱ��� a��° ���ڰ� b�� ��������, 0~9������ ���ڰ� ��� ���� ��쵵 �ְ�,
�׷��� ���� ��쵵 ���� ���̴�. bitmask�� dp[a][b][1024]�� �̿��Ͽ� 0~9�� ���¸� ������ �� �ִ�.
(0~9�� ��� �����ߴٸ� 1023�� �� ���̴�) 
*/

long long dp[101][10][1024] = { 0 };

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < 10; i++) {
		us x = 0; 
		x |= 1 << i;
		dp[1][i][x] = 1;
	}
	
	for (int i = 2; i <= N; i++) {
		for (int k = 0; k < 1024; k++) {
			dp[i][0][k | 1] += dp[i - 1][1][k] % NUM;
			dp[i][9][k | (1 << 9)] += dp[i - 1][8][k] % NUM;
		}
		
		for (int j = 1; j < 9; j++) {
			for (int k = 0; k < 1024; k++) {
				dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % NUM + dp[i - 1][j + 1][k] % NUM;
			}
		}
	}
	
	long long sum;		
	for (int i = 1; i < 10; i++) sum += dp[N][i][1023] % NUM;
	printf("%lld", sum % NUM);
}

