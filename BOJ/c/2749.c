#include <stdio.h>
#define NUM 1000000
#define NUM2 1500000
typedef unsigned long long ull;

/*�Ǻ���ġ ���� 1,000,000���� ���� �������� �ǻ�� �ֱ�= 1,500,000�̴�.*/

int main() {
	ull N; scanf("%lld", &N);
	if (N >= NUM2) N %= NUM2; 
	if (N == 0) { printf("0\n"); return 0; }
	else if (N == 1) { printf("1\n"); return 0; }
	else if (N == 2) { printf("1\n"); return 0; }
	ull A = 1, B = 1, C;
	for (ull i = 2; i < N; i++) {
		C = ((A % NUM) + (B % NUM)) % NUM;
		A = B;
		B = C;
	}
	printf("%lld\n", C);
}

