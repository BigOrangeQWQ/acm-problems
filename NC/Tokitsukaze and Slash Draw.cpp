#include <climits>
// #include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <deque>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

using PII = pair<int, int>;
using LL = long long;

const int N = 1e5 + 10;
const int INF = LONG_LONG_MAX;
vector<PII> E[N];
vector<int> dis(N, INF), vis(N);

int dj(int st, int ed) {
    fill(dis.begin(), dis.end(), INF);
    fill(vis.begin(), vis.end(), false);

    priority_queue<PII, vector<PII>, greater<PII>> q;
    dis[st] = 0;
    q.push({0, st});
    while (!q.empty()) {
        auto x = q.top().y;
        q.pop();

        if(vis[x])
            continue;

        vis[x] = true;
        for(auto v: E[x]) {
            int e = v.x, w = v.y;
            if(dis[e] > dis[x] + w) {
                dis[e] = dis[x] + w;
                q.push({dis[e], e});
            }
        }
    }
    return dis[ed];
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++) E[i].clear();

    for(int i = 1; i <= m ;i ++) {
        int x, y;
        cin >> x >> y;
        for(int i = 0; i < n; i++) 
            E[i].push_back({(i + x) % n,y});
    }

    int res = dj(0, n - k);
    if(res == INF)
        cout << -1 << endl;
    else
        cout << res << endl;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}