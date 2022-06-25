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

	int res, sum=-1;
	rep(i, 5) {
		int a=0;
		rep(j, 4) {
			int x;
			cin >> x;
			a+=x;
		}
		if (sum<a) {
			res=i+1;
			sum=a;
		}
	}
	cout << res << ' ' << sum;

	return 0;
}