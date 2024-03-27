#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

using PII = pair<int, int>;
using LL = long long;

const int N = 1e5 + 10;
vector<int> p[N];
vector<int> siz(N), fa(N);
int cnt;


void dfs(int u, int need) {
    siz[u] = 1;
    for(auto v: p[u]) {
        if(fa[u] != v){
            fa[v] = u;
            dfs(v, need);
            siz[u] += siz[v];
        }
    }
    if(siz[u] >= need) 
        ++cnt, siz[u] = 0;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        p[i].clear();
    siz.clear(), fa.clear();

    for(int i = 1; i < n;i++) {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    
    int l = 1, r = n;
    while(l + 1 < r) {
        int mid = (l + r) >> 1;

        cnt = 0;
        dfs(1, mid); 

        if(cnt > m) l = mid;
        else r = mid; 
    }
    cout << l << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}