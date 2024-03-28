#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define x first
#define y second

using PII = pair<int, int>;
using LL = long long;

const int N = 1e5 + 10;
vector<PII> edges[N];

void add(int x, int y, int d) {
    edges[x].push_back({y, d});
}

int dijkstra(int st, int ed) {
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<bool> cnt(N, false);
    vector<int> dis(N, 2e9);
    
    dis[st] = false;
    q.push({0, st});
    while(q.size()) {
        int u = q.top().y; q.pop();

        if(cnt[u])
            continue;

        cnt[u] = true;
        for(auto ed: edges[u]) {
            int endp = ed.x, w = ed.y;
            int res = max(dis[u], w);
            if(dis[endp] > res) {
                dis[endp] = res;
                q.push({dis[endp], endp});
            }
        }
    }
    return dis[ed];
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for(int i = 1; i <= m;i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, z);
    }
    int res = dijkstra(s, t);
    if(res != 2e9) 
        cout << res << endl;
}