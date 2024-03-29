#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

const int N = 1e5+10;
vector<int> e[N];
int dp[N][2];

void dfs(int u, int fa) {
    dp[u][1] = 1, dp[u][0] = 0;
    for(auto v: e[u]) {
        if(v == fa) 
            continue;
        dfs(v, u);
        dp[u][0] += dp[v][1]; //这次不亮，小子一定要亮
        dp[u][1] += min(dp[v][0], dp[v][1]); //这次亮了，找小子亮和不亮最少的那个
    }
}

void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        for(int i = 1; i <= y; i++) {
            int z;
            cin >> z;
            e[x].push_back(z);
            e[z].push_back(x);
        }
    }
    dfs(0, -1);
    cout << min(dp[0][1],dp[0][0]) << endl;
}

signed main() {
    // int T;cin >> T;
int T = 1;
    while(T --> 0) {
        solve();
    }
}