#include <queue>
#include <utility>
#include <limits.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	deque<p> dq;
	int N, D; cin >> N >> D;
	ll result = LLONG_MIN;
	for (int i = 1; i <= N; i++) {
		ll temp; cin >> temp;
		/*U-V>D�̸� �ĺ����� ���Ե��� �ʴ´�.*/
		while (!dq.empty() && dq.front().second < i - D) dq.pop_front();
		/*���ϴ� ��ġ���� ������ �����ϴ�.*/
		if (!dq.empty()) temp += max(0LL, dq.front().first);
		result = max(result, temp);
		/*���� ���� ���� ���� dq�� �� ������ ũ�ų� ������, �ִ��� �ĺ��� �� �� ����.*/		
		while (!dq.empty() && dq.back().first <= temp) dq.pop_back();
		dq.push_back({ temp, i }); 		
	}
	cout << result << '\n';
}

