#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

const int N = 500500;

vector<vector<int>> fa(N, vector<int> (35));

// vector<vector<int>> cost(31, vector<int> (N));
vector<int> dep(N), lg(N), E[N];
int n, m, s;


void dfs(int u, int p) {
    fa[u][0] = p, dep[u] = dep[p] + 1;

    //处理自己上头 1 2 4 8 的父亲，每次最多跳转log2 dep次。
    for(int i = 1; i <= lg[dep[u]]; i++) 
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    
    for(auto v: E[u]) 
        if(p != v) 
            dfs(v, u);
}


int LCA(int x, int y) {
    if(dep[x] < dep[y]) //x 理应大于 y，不行咱就换
        swap(x, y);
    if(x == y)
        return x;

    //使得x的深度比 y 小
    while(dep[x] > dep[y])
        x = fa[x][lg[dep[x] - dep[y]] - 1];

    //向上跳4 2 .. 1 这样直到父母相等
    for(int i = lg[dep[x]] - 1; i >= 0; i--) 
        if(fa[x][i] != fa[y][i]) 
            x = fa[x][i], y = fa[y][i];
        
    //fa[x][0] 为 x 的父亲
    return fa[x][0];
}

void solve() {
    
    cin >> n >> m >> s;
    for(int i = 1; i <= n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++) 
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i); 
    //每到达一个 2^x 点 + 1

    dfs(s, 0);

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        cout << LCA(x, y) << endl;
    }
}

signed main() {
    cin.tie(nullptr) -> 
        ios::sync_with_stdio(false);
    int T = 1;
    while(T --> 0) {
        solve();
    }
}