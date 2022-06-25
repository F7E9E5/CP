#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int x, y, r;
} wall;

int N, longest;
vector<wall> walls;
vector<int> child[101]; 

int sqr(int a) { return a * a; }

/*a�� b�� �����ϸ� true ��ȯ*/
bool include(wall a, wall b) {
	return a.r > b.r && (sqr(a.x - b.x) + sqr(a.y - b.y) < sqr(a.r - b.r));
}

/*child�� parent�� �ڽ� ����� true ��ȯ*/
bool isChild(int parent, int child) {
	if (!include(walls[parent], walls[child])) return false;
	for (int i = 0; i < N; i++) {
		if (i == parent || i == child) continue;
		if (include(walls[parent], walls[i]) && 
		include(walls[i], walls[child])) return false;
	}
	return true;
}

bool visit[102];

/*root�� ��Ʈ ���� �ϴ� Ʈ�� ����*/
void makeTree(int root) {
	for (int i = 0; i < N; i++) {
		if (!visit[i] && isChild(root, i)) {
			visit[i] = true;
			child[root].push_back(i);
			makeTree(i);
		}
	}
} 

/*root�� ��Ʈ�� �ϴ� ����Ʈ���� ���� ��ȯ*/
int height(int root) {
	if (child[root].empty()) return 0;
	vector<int> heights;
	for (auto i : child[root]) heights.push_back(height(i));
	sort(heights.begin(), heights.end());
	if (heights.size() >= 2) 
		longest = max(longest, heights[heights.size() - 1] + heights[heights.size() - 2] + 2);
	return heights.back() + 1;
}

/*root�� ��Ʈ ���� �ϴ� Ʈ���� ���� �� ��� ã��*/
int solve() {
	longest = 0;
	return max(height(0), longest);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int C; cin >> C;
	while (C--) {
		cin >> N;
		walls.clear(); walls.resize(N);
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < 101; i++) while (!child[i].empty()) child[i].pop_back();
		for (int i = 0; i < N; i++) cin >> walls[i].x >> walls[i].y >> walls[i].r;
		makeTree(0);		
		cout << solve() << '\n';
	}	
}

