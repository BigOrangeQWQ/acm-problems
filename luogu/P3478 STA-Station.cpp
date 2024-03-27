#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

using PII = pair<int, int>;
using LL = long long;

const int N = 1e6 + 10;
int n;
vector<int> tr[N];
vector<int> fa(N), cnt(N), dep(N), dp(N);
pair<int, int> ans;

//遍历所有点计算深度，非自己的父亲即可遍历
//获取旗下拥有点的数目
void dfs(int u, int fa){ 
    cnt[u] = 1, dep[u] = dep[fa] + 1;
    for(auto v: tr[u]) {
        if(fa == v)
            continue; 
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

//对于每个点来说，将它变为根节点后，因为变之前的根节点是其它玩意，**因为它需要上位**，那么它及它旗下的节点的深度一定会降一
//而之前不归他管的那些点，会因为它变成根节点了，深度 + 1，**因为不归他管的那些点会置于他的下位**
void dps(int u, int fa) {
    for(auto v: tr[u]) {
        if(fa == v)
            continue;
        dp[v] = dp[u] - cnt[v] * 2 + n;
        dps(v, u);
    }
}

void solve() {
    cin >> n;
    for(int i = 2; i <= n;i ++) {
        int x, y;
        cin >> x >> y;
        tr[x].push_back(y);
        tr[y].push_back(x);
    }
    
    dfs(1, 1);
    for(int i = 1;i <= n;i++)
        dp[1] += dep[i];//, cout << dep[i] << ' ';
    dps(1, 1);
    for(int i = 1; i <= n; i++) {
        // cout << dp[1] << ' ';
        if(dp[i] > ans.first)
            ans = {dp[i], i};
    }
    cout << ans.second << endl;

    
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}