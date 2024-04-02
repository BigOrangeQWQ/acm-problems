#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;

using LL = long long;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<int> E[N];
vector<bool> vis(N);
vector<int> dis(N), rng(N);

void add(int x ,int y) {
    E[x].push_back(y);
}

int dfs(int u) {
    if(dis[u])
        return dis[u];
    if(E[u].empty())
        return rng[u];

    for(auto v: E[u]) {
        // cout << u << ' ' << v << ' ' << E[u].size() << endl;
        dis[u] = max(
            dis[u],
            dfs(v) + rng[u]
        );
    }
    return dis[u];
}


void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; 
        cin >> x >> x;
        rng[i] = x;
        while(cin >> x) {
            if(x == 0)
                break;
            E[x].push_back(i);
            // cout << x << ' ' << i <<endl;
        }

    }
    // dfs(1, n);
    cout << dfs(1) << endl;

}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}