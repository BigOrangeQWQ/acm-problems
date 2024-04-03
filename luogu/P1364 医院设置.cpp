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
vector<int> E[N];

vector<int> cost(N);
int res = 1e9 + 10;

int dfs(int u, int fa, int dep) {
    if(u == 0)
        return 0;
    
    int cst = dep * cost[u];
    for(auto v: E[u]) {
        if(v != fa) {
            cst += dfs(v, u, dep + 1);
        }
    }
    if(dep == 0)
        res = min(res, cst);
    return cst;
}

void solve() {
    int n;cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        cost[i] = x;
        E[i].push_back(y);
        E[i].push_back(z);
        E[y].push_back(i);
        E[z].push_back(i);
    }
    for(int i = 1; i <= n;i++) {
        dfs(i, 0, 0);
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