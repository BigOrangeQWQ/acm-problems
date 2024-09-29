#include <iostream>
#include <vector>

using namespace std;

using Graph = vector<vector<int>>;

void dfs(int fa, int p, int dep, Graph &g, vector<pair<int,int>>& l) {
    bool flag = false;
    for(auto x: g[p]) {
        if(x != fa) {
            dfs(p, x, dep + 1, g, l);
            flag = true;
        }
    }
    if(flag == false) {
        l.push_back({dep, p});
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n + 1, vector<int>());
    vector<pair<int,int>> l;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(0, 1, 0, G, l);
    for(auto v: l) {
        cout << v.first << ' ' << v.second << endl;
    }
    cout << endl;
}

int main() {
    int T;cin >> T;
    while (T--) {  
        solve();
    }
}