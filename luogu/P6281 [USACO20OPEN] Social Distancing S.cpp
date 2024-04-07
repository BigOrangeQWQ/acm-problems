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

vector<PII> p;
int n, m;

bool check(int x) {
    // cout << x << endl;
    int l = 0, cow = 0;
    for(auto v: p) {
        l = max(v.x, l);
        int r = v.y;
        if(l > r)
            continue;
        int X = (r - l) / x + 1;
        cow += X;
        l = l + X * x;
    }
    return cow >= n;
}


omg() {
    return 10;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m;i ++) {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    
    sort(p.begin(), p.end());

    int l = 1, r = 1e9;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}