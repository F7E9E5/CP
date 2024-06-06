#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	string S;
	cin >> S;
	for (int i=0; i<26; i++) {
		if (S.find(i+'a')==string::npos) {
			cout << char(i+'a');
			return 0;
		}
	}
	cout << "None";

	return 0;
}