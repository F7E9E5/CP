#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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

	int r, b;
	cin >> r >> b;
	for (int l=3; l<=5000; l++) {
		for (int w=3; w<=l; w++) {
			if (r==2*l+2*w-4 && b==(w-2)*(l-2)) {
				cout << l << ' ' << w;
				return 0;
			}
		}
	}

	return 0;
}