#include <stdio.h>

/*postorder�� ���� ������ ����� �θ����̴�. 
Inorder�� �θ��带 �������� ���� Ʈ���� ������ Ʈ���� ������.
Inorder�� �ε����Ͽ� ��������� ���� Ʈ���� ������ Ʈ���� ���ؼ��� ���� �������
��Ʈ�� �߰��� �� �ִ�.*/

int Postorder[100001];
int Inorder[100001];

void rec(int Ins, int Ine, int Pos, int Poe) {
	if (Ins > Ine || Pos > Poe) return;
	if (Ins == Ine) {
		printf("%d ", Inorder[Ine]);
		return;
	}
	printf("%d ", Postorder[Poe]);
	for (int i = Ins; i <= Ine; i++) {
		if (Inorder[i] == Postorder[Poe]) {
			rec(Ins, i - 1, Pos, i - 1 - Ins + Pos);
			rec(i + 1, Ine, i - Ins + Pos, Poe - 1);
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &Inorder[i]); 
	for (int i = 0; i < n; i++) scanf("%d", &Postorder[i]);
	rec(0, n - 1, 0, n - 1);	
}

