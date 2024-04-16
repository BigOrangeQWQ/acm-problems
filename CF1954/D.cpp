#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <deque>

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;

using LL = long long;

const int MOD = 998244353;

void solve() {
    int n, m = 0;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n;i ++) {
        cin >> p[i];
        m += p[i];
    }
    sort(p.begin() + 1, p.end());
    vector<LL> dp(m + 10);
    dp[0] = 1;
    LL res = 0;
    for(int i = 1; i <= n;i ++) {
        for(int j = 0;j <= m;j ++) {
            if(p[i] >= j)
                res += dp[j] % MOD * p[i] % MOD;
            else 
                res += dp[j] % MOD * ((p[i] + j + 1) / 2) % MOD;
            res %= MOD;
        }
        for(int j = m; j >= p[i]; j--) {
            dp[j] += dp[j - p[i]];
            dp[j] %= MOD;
        }
    }
    cout << res % MOD << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}