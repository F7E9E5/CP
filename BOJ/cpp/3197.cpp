#include <stdio.h>
#include <queue>
#define NUM 1501
using namespace std;

typedef struct {
	int r, c;
} info;

info swan[2];
int R, C, time = 0, sn = 0;
bool vis[NUM][NUM] = { false };
char map[NUM][NUM];
queue<pair<int, int> > v, s, n, k;
int rdi[4] = { 1, -1, 0, 0 };
int cdi[4] = { 0, 0, 1, -1 };

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'L') {
				map[i][j] = '.';
				swan[sn].r = i, swan[sn++].c = j;
			}
			if (map[i][j] == '.') v.push(make_pair(i, j));
		}
	}
	
	s.push(make_pair(swan[0].r, swan[0].c)); 
	vis[swan[0].r][swan[0].c] = true;
	
	int time;
	for (time = 0; !vis[swan[1].r][swan[1].c]; time++) {
		/*����0�� ���� �̵������� ��ġ���� ǥ���Ѵ�. �� �� ����1�� ��ġ�� �ִٸ� �����Ѵ�.
		Ȥ�� �������� ���θ��� �ִٸ� �� ������ ���� ���࿡�� ���, ����0�� �̵� ������
		��ġ�� �� ���̹Ƿ� n�� �����Ѵ�.*/
		while (!s.empty()) {
			int row = s.front().first, col = s.front().second; s.pop();
			for (int i = 0; i < 4; i++) {
				int trow = row + rdi[i], tcol = col + cdi[i];
				if (trow < 0 || trow >= R || tcol < 0 || tcol >= C || vis[trow][tcol]) continue;
				else if (map[trow][tcol] == '.') s.push(make_pair(trow, tcol));
				else if (map[trow][tcol] == 'X') n.push(make_pair(trow, tcol));
				vis[trow][tcol] = true;
			}
		}
		
		/*���� �´��� �������� ���δ�. ���� ���࿡���� �̹��� ��� ��������
		��ġ�� ���ؼ��� Ȯ�����ָ� �ȴ�. k�� �����Ѵ�.*/		
		while (!v.empty()) {
			int row = v.front().first, col = v.front().second; v.pop();
			for (int i = 0; i < 4; i++) {
				int trow = row + rdi[i], tcol = col + cdi[i];
				if (trow < 0 || trow >= R || tcol < 0 || tcol >= C) continue;
				else if (map[trow][tcol] == 'X') {
					map[trow][tcol] = '.';
					k.push(make_pair(trow, tcol));
				}
			}
		}
		
		for( ; !n.empty(); n.pop() ) s.push(n.front());
      	for( ; !k.empty(); k.pop() ) v.push(k.front());	
	}
	printf("%d\n", time - 1);
}

