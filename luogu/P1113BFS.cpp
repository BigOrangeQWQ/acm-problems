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
vector<int> dis(N), rng(N), ind(N);

void add(int x ,int y) {
    E[x].push_back(y);
}

void bfs(int n) {
    queue<int> q; 

    for(int i = 1; i <= n; i++)
        if(ind[i] == 0) 
            q.push(i), dis[i] = rng[i];

    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto v: E[u]) {
            if(--ind[v] == 0) 
                q.push(v);
            
            dis[v] = max(dis[v], dis[u] + rng[v]);
        }
    }
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
            ind[i] ++ ;
            // cout << x << ' ' << i <<endl;
        }
    }
    bfs(n);
    int ans = 0;
    for(int i = 1; i <= n; i++) 
        ans = max(ans, dis[i]);
    cout << ans << endl;
    // dfs(1, n);

}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}