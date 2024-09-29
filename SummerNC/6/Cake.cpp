#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;

void dfs(i)

void solve() {
    int n; cin >> n;

    vector<vector<pii>> G(n + 1, vector<pii>());
    vector<int> tag;

    for(int i = 1; i <= n ;i++) {
        int x, y, v;
        cin >> x >> y >> v;
        G[x].push_back({y, v});
    }

}

int main() {
    int T;cin >> T;
    while(T--)
        solve();
}