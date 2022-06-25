#include <stdio.h>

/*�ǻ�� �ֱ�*/
/*m > 2�� ��쿡 k(m)�� ¦���̴�.
������ ¦�� ���� n > 2�� ���ؼ�, k(m) = n�� m�� �׻� �����Ѵ�.
k(m) <= m^2 - 1
k(2^n) = 3*2^(n-1)
k(5^n) = 4*5^n
k(2*5^n) = 6*n
n > 2�϶�, k(10^n) = 15*10^(n-1)*/

int main() {
	int P; scanf("%d", &P);
	while (P--) {
		int N, M; scanf("%d %d", &N, &M);
		int A = 1, B = 1, C, count = 0;
		do {
			C = ((A % M) + (B % M)) % M;
			A = B;
			B = C;
			count++;
		} while (A != 1 || B != 1);
		printf("%d\n", count);
	} 
}

