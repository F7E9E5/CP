#include <queue>
#include <limits.h>
#include <iostream>
using namespace std;

typedef long long ll;

/*dp[i]�� i��° �ұ��� ������ �� ���� �� �ִ� �ִ� ���̶�� �����غ���.
�̶� dp[i]�� i��° �Ҹ� �������� �ʾ��� ��� max(dp[0~i-1])(= dp[i-1])�� �ȴ�.
i��° �Ҹ� �����Ѵٸ�, �ݵ�� i-k~i-1��° �� �� �ϳ��� �������� �ʾƾ� �Ѵ�.
�̶� j(i-k<=j<=i)��° �Ҹ� �������� �ʱ�� �ߴٰ� ����. �׷��� �̶� dp[i]�� 
sum(j+1, i) + dp[j-1]�� �ȴ�. �̷� ������ dp[N]�� ���ϸ� �ȴ�. �׷��� �̶� 
�ð����⵵�� O(N^2)����(prefix sum ���), N�� �ִ��� 10���� ���� ����ϸ� �ʹ� ũ��.
dp[i] = psum[i] - psum[j] + dp[j-1]�̰�, i-k-1<=j<=i�� ��� j�� ���� max�� ã�ƾ� �Ѵ�. 
�������� ���ӵ� K���� ������ ���ĵ� ������ ������ ���� �� �ִٸ�, �����ð��� �����ϴ�. 
BOJ 11003���� �̹� ����� ������� �ذ��� �� �ִ�. �ణ �ٸ� ���̶��, i�� ���� dp�� ���� 
�ٲ�� ������, -psum[j] + dp[j-1]�� ���� ������ �־�� �Ѵٴ� ���̴�.*/

int A[100002], cache[100002], psum[100002] = { 0 };
	
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N, K; cin >> N >> K;
	deque<pair<int, int> > dq;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];	
		psum[i] = psum[i - 1] + A[i];
	}
	for (int i = 1; i <= N; i++) {
		while (!dq.empty() && dq.front().second < i - K) dq.pop_front();
		cache[i] = -psum[i] + cache[i - 1]; 
		while (!dq.empty() && dq.back().first <= cache[i]) dq.pop_back();
		dq.push_back({ cache[i], i });		
		
		/*�� �κп��� ���� �ִ��� �����ش�.*/		
		cache[i] = psum[i] + dq.front().first;
		if (i <= K) cache[i] = max(cache[i], psum[i]);
	}	
	cout << cache[N] << '\n';
}

