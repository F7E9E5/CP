#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

vector<p> event;
int W, cache[1005][1005], choice[1005][1005];

/*�������� ��ġ�� 2�����̶� �ʹ� ���� subproblem�� �����Ѵ�. ��� �ϸ� ���� �� ������?
�����غ��� �������� �����ϴ� ��ġ�� event�� �ִ� �����̴�.
�츮�� �ʿ��� ������ ���� �ֱ��� event�� �����̰�, � �������� �ذ��ߴ����̴�.
�׷��� �� ��쿡�� ������ ������ �� ���� ��ǥ ������ ������ �ʿ��ϴ�.
�ٽ� �����غ��� �׳� ������ ��ġ�� event ��ȣ�� ǥ���ϸ� �� �� ����.  
���� ��� cache[500][501]�̸� 1�� ���� 500�� �ذ��� �����̰�, 2�� ���� 501�� �ذ��� �����̴�.
�� ���� �� ū ���� ���� �ֱٿ� �ذ��� event��� �� �� �ְڴ�.*/

/*���� ù �̺�Ʈ�� ����, event[0, 1]�� ���������� �ʱ� ��ġ�� ���*/

/*�ذ��� ������ ��ȣ�� choice �迭�� ������ ��, ����� ���󰡱⸸ �ϸ� �ȴ�.*/

/*event[a]�� event[b] ���� �Ÿ� ��ȯ*/
int dist(int a, int b) {
	return abs(event[a].first - event[b].first) + abs(event[a].second - event[b].second); 
}

/*1���� ���� �ֱٿ� �ذ��� event�� event1, 2���� ���������϶�,
������ ���� event�� ��� �ذ��ϴ� �� �ҿ�Ǵ� �̵� �Ÿ�*/
int solve(int event1, int event2) {
	int nevent = max(event1, event2) + 1;
	if (nevent - 1 == W + 1) return 0;
	
	int& ret = cache[event1][event2];
	int& choose = choice[event1][event2];
	if (ret != -1) return ret;
	
	int move1 = dist(event1, nevent) + solve(nevent, event2);
	int move2 = dist(event2, nevent) + solve(event1, nevent);
	if (move1 < move2) choose = 1;
	else choose = 2;
	return ret = min(move1, move2);
}

void reconstruct(int event1, int event2, vector<int>& result) {
	int nevent = max(event1, event2) + 1;
	if (nevent - 1 == W + 1) return;
	
	int choose = choice[event1][event2];
	result.push_back(choose);
	if (choose == 1) reconstruct(nevent, event2, result);
	else reconstruct(event1, nevent, result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	memset(cache, -1, sizeof(cache));
	
	int N; cin >> N >> W;
	event.push_back({ 1, 1 }); event.push_back({ N, N }); 
	
	for (int i = 0; i < W; i++) {
		int x, y; cin >> x >> y;
		event.push_back({ y, x });
	}
	cout << solve(0, 1) << '\n';	
	vector<int> result;
	reconstruct(0, 1, result);
	for (auto i : result) cout << i << '\n';
}

