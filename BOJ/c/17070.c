#include <stdio.h>

int N, count = 0; 
int map[17][17];

/*�������� �׻� ������ �Ʒ��θ� �̵��� �� �ֱ� ������ �������� ȸ���� �Ͼ�� �ʴ´�.
�������� �̵��� �� ���� �������� �ڸ��� �̵��� �������� �ڸ��� ������ �� �ڸ� ��ģ��.
���� ������ �պκ��� ��ǥ�� �����ϸ� �ȴ�.*/

void DFS(int row1, int col1, int row2, int col2) {
	if (row2 == N - 1 && col2 == N - 1) { count++; return; }
	if (row1 == row2 && col2 == col1 + 1) {		/*����*/
		if (col2 + 1 < N && !map[row2][col2 + 1]) DFS(row2, col2, row2, col2 + 1);
		if (col2 + 1 < N && row2 + 1 < N 
		&& !map[row2][col2 + 1] && !map[row2 + 1][col2] && !map[row2 + 1][col2 + 1]) {
			DFS(row2, col2, row2 + 1, col2 + 1);
		}
	}
	else if (row1 + 1 == row2 && col1 == col2) {		/*����*/
		if (row2 + 1 < N && !map[row2 + 1][col2]) DFS(row2, col2, row2 + 1, col2);
		if (row2 + 1 < N && col2 + 1 < N 
		&& !map[row2][col2 + 1] && !map[row2 + 1][col2] && !map[row2 + 1][col2 + 1]) {
			DFS(row2, col2, row2 + 1, col2 + 1);
		}
	}
	else { /*�밢��*/
		if (col2 + 1 < N && !map[row2][col2 + 1]) DFS(row2, col2, row2, col2 + 1);
		if (row2 + 1 < N && col2 + 1 < N 
		&& !map[row2][col2 + 1] && !map[row2 + 1][col2] && !map[row2 + 1][col2 + 1]) {
			DFS(row2, col2, row2 + 1, col2 + 1);
		}
		if (row2 + 1 < N && !map[row2 + 1][col2]) DFS(row2, col2, row2 + 1, col2);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	DFS(0, 0, 0, 1);
	printf("%d\n", count);
}

