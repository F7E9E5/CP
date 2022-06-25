#include <stdio.h>

int pos[51] = { 0 }; /*pow[k] = 1 -> ����, 0 -> ����*/ 
int num[51] = { 0 }; /*num[k] = k�� ���� ��Ƽ ��*/
int party[51][51] = { 0 }; /*party[k]�� k��� �������� ���� ��Ƽ�� ���*/
int pnum[51] = { 0 }; /*pnum[k]�� k�� ��Ƽ�� ������ ����*/
int other[51][51] = { 0 }; /*other[k]�� k�� ��Ƽ�� ���� �������� ���*/
int know[51] = { 0 }; /*������ k�� ������ ���ؾ� �ϴ� ����̸� know[k] = 1*/

/*� ��Ƽ�� �� �������� ������ �˰� �ִٸ�, �� ��Ƽ������ ������ ���ؾ� �ϹǷ�,
�� ��Ƽ�� ������ ��� ������ �ƴ� ������� ��޵ȴ�. ���� �� ��Ƽ�� �������� ����
�ٸ� ��Ƽ ���� ������ ���ؾ� �ϴ� ��Ƽ�� �ȴ�. dfs�� �̿��� ������ ������Ű��,
�������� ���� ��Ƽ�� ���� �������� �� �� �ִ� Ƚ���̴�.*/

void DFS(int V) {
	for (int i = 0; i < num[V]; i++) {
		/*V�� ���� i��° ��Ƽ�� ���� ���� ��Ƽ�� �Ǿ���.*/
		if (!pos[party[V][i]]) {
			pos[party[V][i]] = 1;
			/*�� ��Ƽ�� ������ �� ������ �𸣴� ����� ������ �ƴ� ������� �ٲٰ�,
			�� ����� ���� ��Ƽ�� ���ؼ� ���� ������� �����Ѵ�.*/
			for (int j = 0; j < pnum[party[V][i]]; j++) {
				if (!know[other[party[V][i]][j]]) {
					know[other[party[V][i]][j]] = 1;
				}			
				DFS(other[party[V][i]][j]);
			}
		}
	}
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		know[x] = 1;
	} 
	
	/*��Ƽ�� ��ȣ�� 1 ~ M���� ����*/
	for (int i = 1; i <= M; i++) {
		scanf("%d", &pnum[i]);
		
		/*i��° ��Ƽ�� ���� �������� �Է¹޴´�*/
		for (int j = 0; j < pnum[i]; j++) { 
			int a; scanf("%d", &a);
			other[i][j] = a;
			party[a][num[a]++] = i; 
		}
	}
	int count = 0;
	for (int i = 1; i <= N; i++) if (know[i]) DFS(i);
	for (int i = 1; i <= M; i++) if (!pos[i]) count++;
	printf("%d\n", count);
}

