#include <iostream>
#include <string.h>
using namespace std;

/*�ߵ��� ���Ը� ���ϰų�, ���� ������ ���Ը� ���� �� �ִ� ��� �����ϴٰ� �Ѵ�.
�̶� �� �ߵ��� ���õǰų�, ��ġ�ų�, ���ų� 3���� �߿� �ϳ��� �������� �����Ƿ�
�� ���� 3^���� �����̴�. ���� �ִ� ������ 30���̹Ƿ� ��θ� �ϳ��ϳ� ���� �� ����.
�߿��� ���� ���� ������ �� �ʿ䰡 ���ٴ� ���̴�. � ���Ը� �߷� ���� �� �ֱ⸸ �ϸ� �ȴ�.
���� ���԰� 500g�����̱� ������ ������ ������ ������ 0~15000g�̴�.
� ���Ը� ���� ��, �ϳ��� �߿� 3������ ���������� �־����� �ϹǷ�, 
�κ� ������ "N��° �߱��� ����Ͽ� � ���� K�� ���� �� �ִ°�"�� �����Ѵ�.*/
  
/*Ȯ���� ������ �ִ밪�� 40000�ε�, ���� ������ �߸� �����޳�?*/  
  
/*���� ���� : made�� weight[current]���� ũ�ų� ���� ��쿡�� made-weight[current]�� 
�������� �˻��Ͽ��µ�, ���� �̹� ���࿡�� ������ ����(���ǿ����� ���� �ʿ� �߸� �ø��� ��)��
���Դٰ� �ϴ���, ���� ������� ���� made�� 0���� ����� ���� ������ �� �ִ�. ����
cache ũ�⸦ �÷��ְ�, ������ ���ɼ��� ����Ͽ���.*/  
  
int W, weight[31];
int cache[31][30001]; /*1�̸� ����, 0�̸� �Ұ���, -1�̸� ��Ȯ��*/  

/*current���� ����Ͽ� made�� ���� �� �ִ��� ��ȯ�Ѵ�.*/
int solve(int current, int made) {
	if (current == W) return !made ? 1 : 0; 
	
	int& ret = cache[current][made + 15000];
	if (ret != -1) return ret;
	if (solve(current + 1, made)) return ret = 1;
	if (solve(current + 1, made - weight[current])) return ret = 1;
	if (solve(current + 1, made + weight[current])) return ret = 1;
	return ret = 0;
}  

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int N; cin >> W;
	for (int i = 0; i < W; i++) cin >> weight[i];
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		if (x > 15000 || !solve(0, x)) cout << "N ";
		else cout << "Y ";
	}
	cout << '\n';
}

