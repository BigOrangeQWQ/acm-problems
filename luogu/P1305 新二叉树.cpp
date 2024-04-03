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
vector<PII> tr(N);

void dfs(int u) {
    if(u ==0)
        return;
    cout <<(char) u;
    // if(tr[u].x) 
    dfs(tr[u].x);
    dfs(tr[u].y);

}

void solve() {
    int n; cin >> n;
    int flag = false, root;
    while(n --) {
        string v;cin >> v;
        if(!flag)
            root = v[0], flag = true;
        tr[v[0]] = {
            v[1] != '*' ? v[1] : 0,
            v[2] != '*' ? v[2] : 0 
        };
    }
    dfs(root);
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}