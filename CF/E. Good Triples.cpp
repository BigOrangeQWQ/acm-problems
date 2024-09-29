#include <bits/stdc++.h>

using namespace std;
#define int long long

int getv(int x) {
    return (1 + x) * x / 2;
}

void solve() {
    int n; cin >> n;
    int res = 1;
    while(n) {
        res *= getv(n % 10 + 1);
        n /= 10;
    }
    cout << res << endl;
}

signed main() {
    int T; cin >> T;
    while(T--) {
        solve();
    }
}

