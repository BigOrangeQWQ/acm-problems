#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int MOD = 100000000;
#define int long long
#define endl '\n'

int n, m;
vector<int> g[N];
vector<int> s[N];
set<int> pr[N];

int dp[15][500];

//第几行，光标，答案 
void dfs(int i, int cur, int res) {
    if(cur >= m) {
        // cout << i << ' ' << res << endl;
        pr[i].insert(res);
        return;
    }
    //如果它能放
    if(g[i][cur])
        dfs(i, cur + 2, res | (1 << cur));
    dfs(i, cur + 1, res);
}

bool check(int u, int v) {
    return !(u & v);
}

signed main() {
    cin.tie(nullptr) -> ios::sync_with_stdio (false);

    cin >> n >> m;
    for(int i = 1; i <= n;i ++) {
        for(int j = 1; j <= m; j++) {
            int x; cin >> x;
            g[i].push_back(x);
        }
    }

    for(int i = 1; i <= n;i ++) {
        dfs(i, 0, 0);
        s[i] = vector<int>(pr[i].begin(), pr[i].end());
    }

    for(int j = 0; j < s[1].size(); j ++) 
        dp[1][j] = 1;//第一行

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < s[i].size();j++) {
            for(int k = 0; k < s[i - 1].size(); k ++){
                if(check(s[i][j], s[i - 1][k])){
                    dp[i][j] += dp[i - 1][k];
                    dp[i][j] %= MOD;
                }
            }
        }
    }  


    int ans = 0;
    for(int i = 0; i < s[n].size(); i++) {
        ans += dp[n][i];
        ans %= MOD;
        // cout << i << ' ' << dp[n][i] << endl;
    }
    cout << ans % MOD << endl;

    // for(int i = 1; i <= n;i ++) {
    //     dfs(i, 0, 0);
    //     cout << s[i].size() << endl;
    //     for(auto v: s[i]) {
    //         cout << v << ' ';
    //     }
    //     cout << endl;
    // }
}