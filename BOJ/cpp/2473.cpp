#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

/*��� �ϳ��� ���ϰ�, ������ �� ����� Two-pointer Algorithm���� ���Ѵ�. O(N^2)*/

/*���� ���� : ���� 0�� ��츦 ������� �ʾҴ�. start�� �ø����� end�� ���̴��� ����� ���� ������
�ƹ� ���̳� ������ �ذ��ߴ�. ��� ���� 0�� �� �ٷ� �����ص� �ȴ�.*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, result[3];
	ll A[5001], sum, minValue = 3000000003;
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	
	for (int first = 0; first < N - 2; first++) {
		int start = first + 1, end = N - 1;
		while (start < end) {
			sum = A[first] + A[start] + A[end];
			if (abs(sum) < minValue) {
				minValue = abs(sum);
				result[0] = first;
				result[1] = start;
				result[2] = end;	
			}
			if (sum < 0) start++;
			else if (sum > 0 )end--;
			else {
				for (int i = 0; i < 3; i++) cout << A[result[i]] << ' ';
				cout << '\n';
				return 0;
			}
		}	
	}
	
	for (int i = 0; i < 3; i++) cout << A[result[i]] << ' ';
	cout << '\n';
}

