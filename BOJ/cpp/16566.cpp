#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*ö���� �� ī���� ���� �־����� ��, �� ī�庸�� ���ڰ� ū ī��� �� ���� ���� ī�带 ã�ƾ� �Ѵ�.
������ ��������, ī�� ������ 4�鸸���̴�. Union-Find algorithm�� ����� upper_bound�� �θ� 
���� ������ �ϸ� ���� ������? �� merge�� �� index�� ū ���� ����Ű���� �ؾ� �Ѵ�.*/

vector<int> minsu;
int parent[4000001];	/*parent[a] : minsu[a]�� �θ�*/

int find(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, M, K; cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int x; cin >> x;
		minsu.push_back(x);
	}	
	sort(minsu.begin(), minsu.end());
	
	for (int i = 0; i < M; i++) parent[i] = i;
	for (int i = 0; i < K; i++) {
		int x; cin >> x;
		int temp = upper_bound(minsu.begin(), minsu.end(), x) - minsu.begin();
		int tempar = find(temp);
		merge(tempar, tempar + 1);
		cout << minsu[tempar] << '\n';
	}
}

