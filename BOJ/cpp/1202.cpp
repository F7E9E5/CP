#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*���԰� ������ ������� ä��� �����ϴµ�, ���濡 ���� �� �ִ� ���� ��� ������ ���� �ȴ�.*/

int bag[300001];
vector<pair<int, int> > v;
priority_queue<int> pq;	/*��ġ�� ū ���� ����*/

int main() {
	int N, K; scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int M, V; scanf("%d %d", &M, &V);
		v.push_back(make_pair(M, V));
	}
	for (int i = 0; i < K; i++) scanf("%d", &bag[i]);
	
	sort(v.begin(), v.end());
	sort(bag, bag + K); 
	
	int j = 0;
	long long sum = 0;
	for (int i = 0; i < K; i++) {
		while (j < N && v[j].first <= bag[i]) pq.push(v[j++].second);
		if (!pq.empty()) { sum += pq.top(); pq.pop(); }
	}
	printf("%d\n", sum);
}

