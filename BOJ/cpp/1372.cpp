#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#define NUM 12
using namespace std;

/*�ܾ� ���� N���� ���� ������ ������ ������ N!�̴�. 12!�� 5�￡ ����� ���̴�.
� �ܾ �ڿ� ���� ���̸� ���ϴ� �� �ʿ��� ������ ���� �ܾ�� ���ݱ��� ���� �����̴�.
���� �ܾ��� ������ 12��, ���ݱ��� ���� ���̴� �ִ� 12 * 50�̹Ƿ� ������ �����ϴ�.
�׷��� �� �κй����� ���� �ڿ� ���� �ܾ �����ϴ� �� O(N)�� �ð��� �ҿ�ǹǷ�, 
��ü O(MN^2)�� �ð����⵵�� �䱸�ȴ�.

�̶� ���������� ���� ���� ���� ���� �����ؾ� �ϹǷ�, reconstruct()����
���ڿ��� �籸���� �� �ĺ� ���ڿ��� �� ���� ���������� ���� ���� �����Ѵ�.
�� �ܰ踶�� ���� ���� ���� �����ϹǷ� �� ��� ���� ���������� ���� ������.*/

int N;
string words[NUM + 1];
bool jump[NUM + 1] = { false }; /*� ���ڿ��� �ٸ� ���ڿ��� ���ԵǸ� jump*/
int overlap[NUM + 1][NUM + 1], cache[NUM + 1][1 << NUM];

/*������ ������ last�̰�, ���ݱ��� used�� ������� �� ������ ���� ���ڿ�����
�߰��Ͽ� ���� �� �ִ� overlap�� �ִ밪 ��ȯ*/
int restore(int last, int used) {
	if (used == (1 << N) - 1) return 0;
			
	int& ret = cache[last][used];
	if (ret != -1) return ret;
	
	ret = 0;
	for (int next = 0; next < N; next++) {
		if (jump[next] || used & (1 << next)) continue;
		int temp = overlap[last][next] + restore(next, used | (1 << next));
		ret = max(ret, temp);
	}
	return ret;
}

string rcache[NUM + 1][1 << NUM];
string reconstruct(int last, int used) {
	if (used == (1 << N) - 1) return "";
	
	string& ret = rcache[last][used];
	if (ret != "e") return ret;
	
	vector<string> results;
	for (int next = 0; next < N; next++) {
		if (jump[next] || (used & (1 << next))) continue;
		
		int ifUsed = overlap[last][next] + restore(next, used | (1 << next));
		if (ifUsed == restore(last, used))
			results.push_back(words[next].substr(overlap[last][next])
			 + reconstruct(next, used | (1 << next)));
	}
	sort(results.begin(), results.end());
	return ret = results[0];
}

void precalc() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j || (jump[i] || jump[j])) continue;
			
			for (int l = 0; l <= (int)words[i].size(); l++) {
				int compared = min(words[i].size() - l, words[j].size());
				if (words[i].substr(l, compared) == words[j].substr(0, compared)) {
					if (compared == (int)words[j].size()) jump[j] = true;
					overlap[i][j] = compared;
					break;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> words[i];
	
	int base = 0;
	memset(cache, -1, sizeof(cache));
	fill_n(&rcache[0][0], (NUM + 1) * (1 << NUM), "e");
	
	precalc();
	for (int i = 0; i < N; i++) if (jump[i]) base |= (1 << i);
	
	vector<string> results;	
	int resultValue = -1;
	for (int i = 0; i < N; i++) {
		if (jump[i]) continue;
		int temp = restore(i, base | (1 << i));
		resultValue = max(resultValue, temp);
	}	
	for (int i = 0; i < N; i++) {
		if (jump[i]) continue;
		if (restore(i, base | (1 << i)) == resultValue) 
			results.push_back(words[i] + reconstruct(i, base | (1 << i)));
	}
	sort(results.begin(), results.end());
	cout << results[0] << '\n';
}

