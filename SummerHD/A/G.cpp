#include <iostream>

using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    ll ans = 0;
    int cnt = __builtin_popcount(n);
    int newn = 0;
    for(int i = 1;i <= cnt; i++) {
        newn <<= 1;
        newn += 1;
    }
    // cout << newn << endl;
    for(int i = 0; i <= newn;i ++) {
        int xorv = __builtin_popcount(i & newn);
        ans += (ll) (1 << k) * (1 << k) * (1 << xorv);
        // cout << (i & n) << ' ' << (1 << xorv) << ' ' <<  i << ' ' << (1 << k) * (1 << k) * (1 << xorv) << endl;
    }
    cout << ans << endl;
}l

int main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    
    int T;cin >> T;
    while(T--)
        solve();
}