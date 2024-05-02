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

const int N = 2e5+10;
int dp[N][2];
vector<int> E[N];

void dfs(int u, int fa) {
    dp[u][1] = 1, dp[u][0] = 0;
    for(auto v: E[u]) {
        if(v != fa) {
            dfs(v, u);
            dp[u][1] += min(dp[v][0], dp[v][1]);
            dp[u][0] += dp[v][1];
        }
    }
}

void dfs2() {
    //不会
}

void solve() {
    // int n;
    // cin >> n;
    // for(int i =1; i <= n;i ++) {
    //     int x, y;
    //     cin >> x >> y;
    //     E[x].push_back(y);
    //     E[y].push_back(x);
    // }
    // dfs(3, -1);
    // for(int i = 1; i <= n;i ++) {
    //     cout << dp[i][1] << " \n"[i == n];
    // }
    // for(int i = 1; i <= n;i ++) {
    //     cout << dp[i][0] << " \n"[i == n];
    // }
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}