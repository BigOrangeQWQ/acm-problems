#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define endl '\n'
#define x first
#define y second
const int N = 1e5 + 10;
const int INF = 2e9 + 10;
using PII = pair<int, int>;
vector<pair<int,int>> E[N];
vector<int> vis(N), dis(N);

int dj(int st, int ed) {
    fill(vis.begin(), vis.end(), false);
    fill(dis.begin(), dis.end(), INF);

    priority_queue<PII, vector<PII>, greater<PII>> p;
    p.push({0, st});
    dis[st] = 0;
    while(p.size()) {
        auto x = p.top().y; p.pop();
        
        if(vis[x])
            continue;

        vis[x] = true;
        for(auto v: E[x]) {
            int ed = v.x, w = v.y;
            if(dis[ed] > dis[x] + w) {
                dis[ed] = dis[x] + w;
                p.push({dis[ed], ed});
            }
        }
    }
    return dis[ed];
}

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n, st, ed;
    cin >> n >> st >> ed;
    for(int i = 1; i <= n;i++) {
        int k; cin >> k;
        for(int j = 1; j <= k; j++) {
            int x; cin >> x;
            // cout << i << ' ' << x << ' ' << (j != 1) << endl;
            E[i].push_back({x, j != 1});
        }
    }
    int res = dj(st, ed);
    if(res == INF)
        cout << -1 << endl;
    else 
        cout << res << endl;
    // cout << 1 << endl;
}