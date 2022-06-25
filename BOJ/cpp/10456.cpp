#include <stdio.h>
#include <stdbool.h>
#include <algorithm>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

/*
n���� ���� ���� �ּ� �Һ�ݾ� c[n] 
-> MIN(c[n-1] + �׳� ����, c[n-1] + ���� Ƽ��, c[n-7] + ���̿��, c[n-30] + ���̿��)

travel ticket�� ���ΰ� ���� �̿�ῡ�� ������ ��ġ�� ������ �� ���� possibile choices 
c[n-1] + �׳� ����, c[n-1] + ���� �̿�� + ���� �׳�, c[n-1] tt
c[n-7] + ���� �� �̿�� + ���� �׳�, c[n-7] + ���� �� �̿�� + ���� �� �̿��(�� �ϸ��� ����)
c[n-7] + ���� �� �̿��, c[n-30] + ���� �� �̿�� + ���� �׳�, 
c[n-30] + ���� �� �̿�� + ���� ��/���̿��, c[n-30] + ���� �̿��  (�� ���� ����)

� Ƽ���� ������� �߿����� �ʱ� ������(Ƽ���� �ߺ� ���),  �Һ�ݾ׸��� �����ϸ� �ȴ�.
��ü �̿��� ���� �̿�Ḧ ���� �����ؾ� �� ���ϴ�. �̶� ���� �̿���� ������ ä�� 
���� �̿���� �����Ϸ� �� ���� ����� ����ϱ� ���ؼ��� �ֱ� 1��, 7��, 30�ϰ��� ���� �̿��
�ּڰ��� �ʿ��ϴ�. ������ �Ⱓ ���� �Һ� ����̱� ������ ����ؼ� ���ο� ���� �����־�� �Ѵ�. 
 */
 
int dp[10001] = { 0 }; 
int bus[10001] = { 0 }; 
int train[10001] = { 0 }; 

int recent7(int end) {
	int ans = 0;
	int start = (end - 6) > 0 ? (end - 6) : 1;
	for (int i = start; i < end + 1; i++) ans += MIN(train[i], 6);
	return ans;
}

int recent30(int end) {
	int temp[31] = { 0 }, k = 1;
	int start = (end - 29) > 0 ? (end - 29) : 1;
	for (int i = start; i < end + 1; i++, k++) {
		temp[k] = temp[k - 1] + MIN(train[i], 6);
		if (k > 7) temp[k] = MIN(temp[k], temp[k - 7] + 36);
		else temp[k] = MIN(temp[k], 36);
	}
	return temp[k - 1];
}


int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int a, b; scanf("%d %d", &a, &b);
			bus[i] = a, train[i] = b * 2;
		}
		
		for (int i = 1; i <= n; i++) {
			if (i < 7) {
				dp[i] = min({
					dp[i - 1] + bus[i] + train[i],
					dp[i - 1] + 3 + train[i],
					dp[i - 1] + 6,
					18 + recent7(i),
					36,
					45 + recent30(i),
					90
				});
			}
			else if (i < 30) {
				dp[i] = min({
					dp[i - 1] + bus[i] + train[i],
					dp[i - 1] + 3 + train[i],
					dp[i - 1] + 6,
					dp[i - 7] + 18 + recent7(i),
					dp[i - 7] + 36,
					45 + recent30(i),
					90
				});
			}
			else {
				dp[i] = min({
					dp[i - 1] + bus[i] + train[i],
					dp[i - 1] + 3 + train[i],
					dp[i - 1] + 6,
					dp[i - 7] + 18 + recent7(i),
					dp[i - 7] + 36,
					dp[i - 30] + 45 + recent30(i),
					dp[i - 30] + 90
				});
			}
			
			printf("%d %d %d\n", dp[i], recent7(i), recent30(i));
		}
		
		printf("%d\n", dp[n]);
	}
}

