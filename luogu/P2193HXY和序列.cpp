#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e3 + 20;
const int MOD = 1e9 + 7;

int dp[N][N];

signed main() {
    int n, p;
    cin >> n >> p;
    for(int i = 1; i <= n;i ++)
        dp[1][i] = 1;

    for(int i = 1; i <= p; i ++) {
        for(int j = 1; j <= n; j ++) {
            for(int k = 1; k * j <= n; k++) {
                dp[i][j * k] += dp[i - 1][j];
                dp[i][j * k] %= MOD;
            }
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res = (res + dp[p][i]) % MOD;
    }
    cout << res << endl;
}