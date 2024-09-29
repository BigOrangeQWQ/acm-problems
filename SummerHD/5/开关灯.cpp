#include <iostream>

#define int long long
using namespace std; 

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    int MOD = 998244353;
    if(n <= 2) {
        cout << 2 << "\n";
        return;
    }
    if(n % 3 == 2) {
        n --;
    }
    cout << binpow(2, n, MOD) % MOD << "\n"; 
// 1 3 4 4 6 7 7 9
// 2 3 4 5 6 7 8 9
}

signed main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    int T;cin >> T;
    while(T--)
        solve();
}