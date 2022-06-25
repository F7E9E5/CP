#include <iostream>
using namespace std;

/*Brute-Force*/

/*�ִ� ��� 4^26�̶� ����������, ������ �׸� ���� ���� ���ϴ�.
���õ��� ���� ���ĺ����� ���󰡹Ƿ�, �ϳ��� ��쿡 ���� ���� ��� �ð��ΰ�?*/

int R, C;
char board[22][22];
bool check[27] = { false };

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

/*������ �� ���ư� �� �ִ� �ִ� ĭ �� ��ȯ, ���� ĭ ����*/
int DFS(int y, int x) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny > R || ny < 1 || nx > C || nx < 1 || check[board[ny][nx] - 'A']) continue;
		check[board[ny][nx] - 'A'] = true;
		ret = max(ret, DFS(ny, nx) + 1);
		check[board[ny][nx] - 'A'] = false;
	}	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		
	cin >> R >> C;
	string temp;
	for (int i = 1; i <= R; i++) {
		cin >> temp;
		for (int j = 1; j <= C; j++) board[i][j] = temp[j - 1];
	}
	check[board[1][1] - 'A'] = true; 
	cout << DFS(1, 1) << '\n';
}

