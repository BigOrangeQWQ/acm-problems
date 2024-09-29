#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
vector<int> E[N];
map<pair<int, int>, int> res;
// vector<vector<int>> dp(2, vector<int>(N));
int dp[N][2];

void dfs1(int u, int fa) {
    dp[u][1] = 1;
    dp[u][0] = 0;
    for(auto t: E[u]) {
        if(t == fa) continue;
        dfs1(t, u);

        dp[u][1] += min(dp[t][1], dp[t][0]);
        dp[u][0] += dp[t][1];
    }
    // cout << dp[u][1] << ' ' << dp[u][0] << endl;
}

void dfs2(int u, int fa) {
    for(auto t: E[u]) {
        if(t == fa) continue;
        int fst1 = dp[u][1] - min(dp[t][1], dp[t][0]);
        int fst2 = dp[u][0] - dp[t][1];
        int ans = min(dp[t][0], dp[t][1]) + min(fst1, fst2);
        // cout << u << ' ' << t << ' ' << ans << endl;
        res[{t, u}] = ans;
        res[{u, t}] = ans;
        dp[t][0] += fst1;
        dp[t][1] += min(fst1, fst2);
        dfs2(t, u);
    }
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> q;
    res.clear();
    for(int i = 1; i <= n; i++) {
        E[i].clear();
    }
    for(int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        q.push_back({x, y});
        E[x].push_back(y);
        E[y].push_back(x);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for(int i = 0; i < n - 1; i++) {
        cout << n - res[q[i]] <<" \n"[i == n - 2];
    }
    // for(auto i: q) {
    //     cout << n - res[i] << endl;
    // }
    // cout << endl;
}

int main() {
    int T;cin>>T;
    while(T--)
        solve();
}