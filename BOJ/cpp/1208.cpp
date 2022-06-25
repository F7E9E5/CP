#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*40���� ������ �־�����, �κм����� ���� S�� ����� ���� ã�ƾ� �Ѵ�. �ܼ��� ����Ž������ ���Ѵٸ�
2^40���� ��û���� ū ���� ���´�. �׷��� �迭�� ������ �ɰ��ٸ� 2^20���� 100�� ���� ũ�Ⱑ �ȴ�.
�̸� ���� �迭�� ���� ���� ����, ���� �迭 �������� ���� S�� ���� ã��, �� ������ �������
��ü �迭���� ���� S�� ���� ã�� �� �ִ�.*/

/*S�� 0�̸� �ƹ� ��ҵ� �������� �ʴ� �κм����� ���Եȴ�. �������� ũ�Ⱑ ����� �κм�������
����ϹǷ�, S�� 0�̸� ���� �������� 1�� ���ش�.*/

void calc(int current, int sum, const vector<int>& src, vector<int>& result) {
	if (current == src.size()) {
		result.push_back(sum);
		return;
	}
	calc(current + 1, sum, src, result);
	calc(current + 1, sum + src[current], src, result);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, S; cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	
	vector<int> sum1, sum2;
	vector<int> A1(A.begin(), A.begin() + A.size() / 2);
	vector<int> A2(A.begin() + A.size() / 2, A.end());
	
	calc(0, 0, A1, sum1); sort(sum1.begin(), sum1.end()); 
	calc(0, 0, A2, sum2); sort(sum2.begin(), sum2.end());
	
	ll count = 0;
	for (auto i : sum1) {
		auto a = lower_bound(sum2.begin(), sum2.end(), S - i);
		auto b = upper_bound(sum2.begin(), sum2.end(), S - i);
		count += (ll)(b - a);
	}
	
	if (!S) count--;
	cout << count << '\n';	
}

