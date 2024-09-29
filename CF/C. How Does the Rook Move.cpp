#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int free = n;
    for(int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        if(x == y)
            free--;
        else 
            free-=2;
    }
    vector<int> dp(n + 10);
    dp[0] = dp[1] = 1;
    for(int i = 2;i <= free;i++) {
        dp[i] = dp[i - 1] + dp[i - 2] * (i - 1) * 2;
        dp[i] %= (int) 1e9 + 7;
    }
    cout << dp[free] << endl;
}

signed main() {
    int T;cin >> T;
    while(T--) {
        solve();
    }
}