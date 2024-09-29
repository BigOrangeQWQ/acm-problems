#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
#define int long long

constexpr ll mod = 998244353;
constexpr ll inv2 = (mod + 1) / 2; //1/2的逆元，×inv后取模得效果

signed main() {
    int n, k, ans = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;

    vector<vector<int>> C(32, vector<int>(32));
    for (int i = 0; i < 31; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }

    vector<vector<int>> dp(n + 2, vector<int>(k + 1, 0));
    for(int i = 1 ; i <= n ; i++) {
        if(s[i] == '1' || s[i] == '?') {
            for(int j = 0;j <= k; j++) {
                for(int t = 0; t <= j; t++) {
                    dp[i][j] = (dp[i][j] + C[j][t] * dp[i - 1][j - t] % mod) % mod;
                }
                dp[i][j] = (1 + dp[i][j]) % mod;
                if(s[i] == '?')
                    dp[i][j] = dp[i][j] * inv2 % mod;
                
            }
            ans = (dp[i][k] + ans) % mod;
        }
    }
    cout << ans << '\n';
}