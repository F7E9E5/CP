#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n%9==0 || (n-2)%3==0) {
            cout << "TAK\n";
        }
        else cout << "NIE\n";
    }

    return 0;
}
