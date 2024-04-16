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

void solve() {
    int n, m = 0;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n;i ++) {
        cin >> p[i];
        m += p[i];
    }
    sort(p.begin() + 1, p.end());
    vector<int> dp(m + 1);
    dp[0] = 1;
    LL res = 0;
    for(int i = 1; i <= n;i ++) {
        for(int j = 0;j <= m;j ++) {
            if(p[i] > j)
                res += dp[j] * p[i];
            else 
                res += dp[j] * ((p[i] + j + 1) / 2);
        }
        for(int j = m; j >= dp[i]; j--) {
            dp[j] += dp[j - dp[i]];
        }
    }
    cout << res << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}