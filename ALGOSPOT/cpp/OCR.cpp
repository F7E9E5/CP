#include <cmath>
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
using namespace std;

int n, m;
int sentence[101];	/*�ؼ���*/

int choice[101][501];
double cache[101][501];

string words[501];
double B[501];	/*���� ó���� ������ Ȯ��*/
double T[501][501];	/*T[a][b] a ���� �ܾ b�� Ȯ��*/
double M[501][501]; /*M[a][b] a�� b�� �з��� Ȯ��*/

/*�ؼ����� �־����� ��, i-1���� ä���� ������ �ĺ��� �� � �ڸ� i���� �ܾ� a�� ������ Ȯ����
i-1�� �ܾ��� ���� �ܾ a�� Ȯ�� * �ؼ����� i�ڸ� �ܾ a�� �з��� Ȯ�� * i+1���� ������
ä���� �� Ȯ�� �� �ϳ�(�ܾ� ������ŭ�� ����� ��) 
���⼭ i ���ĸ� ���� ä���� �� ������ �ִ� Ȯ������ ��������� ���Ѵ�.*/

/*���� ���� : cache �ʱ�ȭ�� ������*/

/*current���� ä���� ���� �� �ִ� �ִ� Ȯ����(�α�) ��ȯ*/
double solve(int current, int previous) {
	if (current == n) return 0.0;
	
	double& ret = cache[current][previous];
	if (ret != 1.0) return ret;
	
	ret = -1e200;
	int& choose = choice[current][previous]; 
	
	for (int thisMatch = 0; thisMatch < m; thisMatch++) {
		double cand = T[previous][thisMatch] + M[thisMatch][sentence[current]]
		+ solve(current + 1, thisMatch);
		
		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
	return ret;
}

void reconstruct(int current, int previous, vector<string>& result) {
	if (current == n) return;
	int choose = choice[current][previous];
	result.push_back(words[choose]);
	reconstruct(current + 1, choose, result);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	double x;
	int q; cin >> m >> q;
	for (int i = 0; i < m; i++) cin >> words[i];
	for (int i = 0; i < m; i++) {
		cin >> B[i]; B[i] = log(B[i]);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> T[i][j]; T[i][j] = log(T[i][j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j]; M[i][j] = log(M[i][j]);
		}
	}
	for (int i = 0; i < q; i++) {
		cin >> n;
		
		fill(&cache[0][0], &cache[0][0] + 101 * 501 + 1, 1.0);
		
		for (int j = 0; j < n; j++) {
			string temp; cin >> temp;
			for (int k = 0; k < m; k++) {
				if (temp == words[k]) {
					sentence[j] = k;
					break;
				}
			}
		}
		
		int start;
		double max = -1e200;
		for (int j = 0; j < m; j++) {
			double temp = B[j] + M[j][sentence[0]] + solve(1, j);
			if (max < temp) {
				start = j;
				max = temp;
			}
		}
		
		vector<string> result;
		result.push_back(words[start]);
		reconstruct(1, start, result);		
		for (int i = 0; i < result.size() - 1; i++) cout << result[i] << ' ';
		cout << result[result.size() - 1] << '\n';
	} 
}

