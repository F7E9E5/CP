#include <vector> 
#include <iostream>
#include <algorithm>
using namespace std;	

int best;									/*��������� ������*/
int blockSize;								/*����� ũ��*/
int covered[10][10];						/*1�̸� ���� ĭ Ȥ�� ���� ĭ, 0�̸� �� ĭ*/
int boardH, boardW; vector<string> board;	/*�������� ����*/
vector<vector<pair<int, int> > > rotations;	/*����� �� ȸ���� ������ ��� ��ǥ*/

/*2���� �迭 arr�� �ð�������� 90�� ���� ����� ��ȯ�Ѵ�.*/
vector<string> rotate(const vector<string>& arr) {
	vector<string> ret(arr[0].size(), string(arr.size(), ' '));
	for (int i = 0; i < arr.size(); i++) 
		for (int j = 0; j < arr[0].size(); j++) 
			ret[j][arr.size() - i - 1] = arr[i][j];
	return ret;
}

bool prune(int placed) {
	int count = 0;
	for (int i = 0; i < boardH; i++) {
		for (int j = 0; j < boardW; j++) {
			if (!covered[i][j]) count++;
		}
	}
	if (best >= placed + count / blockSize) return true;
	else return false;
}
/*block�� �� ���� ȸ�� ���¸� ����� �̵��� ��� ��ǥ�� ������� ��ȯ�Ѵ�.*/
void generateRotations(vector<string> block) {
	rotations.clear(); rotations.resize(4);
	
	for (int rot = 0; rot < 4; rot++) {
		int originY = -1, originX = -1;
		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < block[0].size(); j++) {
				if (block[i][j] == '#') {
					if (originY == -1) {
						originY = i;
						originX = j;
					}
					rotations[rot].push_back({i - originY, j - originX});
				}
			}
		}
		block = rotate(block);
	}
	
	/*�� ���� ȸ�� ���� �� �ߺ��� ���� ��� �̸� �����Ѵ�.*/
	sort(rotations.begin(), rotations.end());
	rotations.erase(unique(rotations.begin(), rotations.end()), rotations.end());
	
	/*����� �� ĭ ¥������ ������ �д�.*/
	blockSize = rotations[0].size();
} 

/*(y, x)�� ���� ��ĭ���� �ؼ� �־��� ����� delta = 1�̸� ����, -1�̸� ���ش�.*/
/*����� ���� �� �̹� ���� ����̳� ���� ĭ�� ��ġ�� ������, �ƴϸ� ���� ��ȯ�Ѵ�.*/
bool set(int y, int x, const vector<pair<int, int> >& block, int delta) {
	bool flag = true;
	for (auto i : block) {
		int ny = y + i.first, nx = x + i.second;
		if (ny >= boardH || ny < 0 || nx >= boardW || nx < 0) {
			flag = false; continue;
		}
		if (covered[ny][nx]) flag = false;
		covered[ny][nx] += delta;
	}	
	return flag;
} 

/*placed : ���ݱ��� ���� ����� ��*/
void search(int placed) {
	if (prune(placed)) return;
	
	/*���� ä�� ���� �� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�.*/
	int y = -1, x = -1;
	for (int i = 0; i < boardH; i++) {
		for (int j = 0; j < boardW; j++) {
			if (!covered[i][j]) {
				y = i, x = j;
				break;
			}
		}
		if (y != -1) break;
	} 
	
	/*���� ��� : �������� ��� ĭ�� ó���� ���*/
	if (y == -1) {
		best = max(best, placed);
		return;
	}
	
	/*�� ĭ�� ���´�.*/
	for (auto i : rotations) {
		if (set(y, x, i, 1)) search(placed + 1);
		set(y, x, i, -1);
	}
	
	/*�� ĭ�� ���� �ʰ� '����'�д�.*/
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}

int solve() {
	best = 0;
	for (int i = 0; i < boardH; i++) {
		for (int j = 0; j < boardW; j++) {
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}
	search(0);
	return best;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while (T--) {
		int R, C;
		board.clear();
		cin >> boardH >> boardW >> R >> C;
		for (int i = 0; i < boardH; i++) {
			string temp; cin >> temp;
			board.push_back(temp);
		}
		
		vector<string> block;
		for (int i = 0; i < R; i++) {
			string temp; cin >> temp;
			block.push_back(temp);	
		}
		generateRotations(block);
			
		cout << solve() << '\n';
	}
}

