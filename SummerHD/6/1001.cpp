#include <iostream>
#include <vector>


using namespace std;


void solve() {
    int n; cin >> n;
    vector<vector<int>> G(n + 1, vector<int>());

    vector<int> fa(n + 1);
    for(int i = 1; i <= n;i ++) {
        fa[i] = i;
    }
    auto find = [&](auto &&self, int x) -> int {
        if(fa[x] != x) 
            return fa[x] = self(self, fa[x]); 
        return x;
    };

    for(int i = 0; i < n - 1;i ++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);

        fa[find(find, x)] = find(find, y);
    }

    int flag = false;
    for(int i = 1; i <= n; i++) {
    }
}

int main() {

    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    int T;cin >> T;
    while(T--)
        solve();
}

