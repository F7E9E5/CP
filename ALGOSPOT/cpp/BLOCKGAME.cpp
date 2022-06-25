#include <vector>
#include <iostream>
using namespace std;

inline int cell(int y, int x) { return 1 << (y * 5 + x); }

vector<int> moves;
char cache[1 << 25];

/*���忡 ����� ���� ��� ��츦 int������ ����Ѵ�.*/
void precalc() {
	/*�� ĭ¥��*/
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			int sum = 0, cells[4];
			for (int dy = 0; dy < 2; dy++) {
				for (int dx = 0; dx < 2; dx++) {
					cells[dy * 2 + dx] = cell(y + dy, x + dx);
					sum += cells[dy * 2 + dx];
				}
			}
			for (int i = 0; i < 4; i++) moves.push_back(sum - cells[i]);
		}
	}
	
	/*�� ĭ¥��*/
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			moves.push_back(cell(i, j) + cell(i, j + 1));
			moves.push_back(cell(j, i) + cell(j + 1, i));
		}
	}
}

/*���� ���� ���°� current�� ��, ���� ������ ����� �¸��ϸ� 1, �ƴϸ� 0 ��ȯ*/
char solve(int current) {
	char& ret = cache[current];
	if (ret != -1) return ret;
	
	ret = 0;
	/*������ ��� �� �߿���*/
	for (int i = 0; i < moves.size(); i++) {
		/*�� ���� ���� �� �ְ�, �� ���� ������ �� ���� ����� �й��Ѵٸ�*/
		if (!(moves[i] & current) && !solve(current | moves[i])) {
			ret = 1;
			break;
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	precalc();
	
	int C; cin >> C;
	while (C--) {
		int base = 0;
		fill_n(cache, 1 << 25, -1);
		
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				char x; cin >> x;
				if (x == '#') base |= cell(i, j);
			}	
		}
		if (solve(base)) cout << "WINNING\n";
		else cout << "LOSING\n";
	}	
}

