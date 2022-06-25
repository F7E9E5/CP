#include <stdio.h>
#include <stdbool.h>

/*� ���� a(b)�� ���� a(1)�� ��ġ�� �̵��ϴµ� ��� ���
1.���� = b�� 1�� ������ ������ ���� �Űܺ���.
2.������ = ��ü ������ �������� ������ ����.

���������� ���� �Űܺ��� ���� �� ������ϴ�. (�����)

���� ���� - ���� ť�� ���� ù ���� ��ġ�� �����ϴ� pointer��� ������
���Ҹ� �̾Ƴ��� �������� �ܼ��� 1�� ���ϱ⸸ �ߴ�.*/

int main() {
	int N, M, answer = 0, pointer = 1;
	bool arr[51] = { false };
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int order, count = 0; scanf("%d", &order);
		for (; pointer != order; pointer = pointer % N + 1) 
			if (!arr[pointer]) count++;
		answer += count < N - i - count ? count : N - i -count;
		pointer = pointer % N + 1;
		arr[order] = true;
	}
	printf("%d\n", answer);
}

