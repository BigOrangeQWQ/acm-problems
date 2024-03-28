#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> e[N];
vector<int> d1(N), d2(N);
int res;

void dfs(int u, int fa) {
    d1[u] = d2[u] = 0;
    for(auto v: e[u]) {
        if(v == fa) 
            continue;
        dfs(v, u);
        int t = d1[v] + 1;
        if(t > d1[u])
            d2[u] = d1[u], d1[u] = t;
        else if(t > d2[u])
            d2[u] = t; 
    }
    //cout << u << ' ' << d2[u] << ' ' << d1[u] << endl;
    res = max(res, d2[u] + d1[u]);
}

int main() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1, 0);
    cout << res << endl;
}