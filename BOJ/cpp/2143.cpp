#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

/*prefix sum�� ����ϸ� ��� �ð��� ���� �� �迭�� ���� ���� �� �ִ�.
�̶� ����Ž������ �����Ѵٸ� ������ �ִ� ����� ���� 1000^4�̹Ƿ� �ʹ� ����.
���ؼ� T�� �Ǵ� ��츦 ���ϸ� �Ǳ� ������ Two-Pointer�� �ذ��غ���.
������ ������ �� �迭 ���� ���� ���� �� �������� �����Ѵ�.
ù �迭�� ó����, �ٸ� �迭�� �������� �����͸� ���ٳ��� ���� ������ ã�´�.*/

void getSum(int* src, vector<ll>& sum, int size) {
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < i; j++) {
			sum.push_back((ll)src[i] - (ll)src[j]);
		}
	}	
	sort(sum.begin(), sum.end());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int x, T, n, m; cin >> T >> n;
	int A[1001] = { 0 }, B[1001] = { 0 };
	for (int i = 1; i <= n; i++) { cin >> x; A[i] = A[i - 1] + x; } 
	cin >> m;
	for (int i = 1; i <= m; i++) { cin >> x; B[i] = B[i - 1] + x; }
	
	vector<ll> sumA, sumB;
	getSum(A, sumA, n); getSum(B, sumB, m);
	
	ll count = 0;
	int left = 0, right = sumB.size() - 1;	
	while (left < sumA.size() && right >= 0) {
		ll sum = sumA[left] + sumB[right];
		if (sum < T) left++;
		else if (sum > T) right--;
		else {
			ll a = 1, b = 1;
			while (left < sumA.size() - 1 && sumA[left] == sumA[left + 1]) left++, a++;
			while (right > 0 && sumB[right] == sumB[right - 1]) right--, b++;
			count += a * b;
			left++;
		}
	}
	cout << count << '\n';
}

