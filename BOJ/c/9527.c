#include <stdio.h>

/*Prefix Sum*/
/*A~B������ 1�� ���� �� = 0~B������ 1�� ���� �� - 0~A-1������ 1�� ���� ��*/

typedef long long ll;
ll t[64] = { 0 };

ll solve(ll A) {
	int arr[64] = { 0 };
	for (int i = 0; i < 63; i++) arr[i] = A / (1LL << i) % 2;
	
	ll sum = 0, num = 0;
	for (int i = 62; i > 0; i--) {
		if (arr[i]) {
			sum += t[i - 1] + num * (1LL << i);
			num++;
		}
	}
	
	if (arr[0]) return sum + num * 2 + 1;
	else return sum + num;
}

int main() {
	ll A, B; scanf("%lld %lld", &A, &B);
	t[0] = 1;
	for (int i = 1; i < 64; i++) t[i] = t[i - 1] * 2 + (1LL << i);
	printf("%lld\n", solve(B) - solve(A - 1));
}

