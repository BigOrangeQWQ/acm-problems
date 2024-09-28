#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), ord(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i = 0; i < n; i++) 
        cin >> b[i];
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        return b[i] > b[j];
    });
    int v1 = 0, v2 = 0, res = 0;
    set<pair<int, int>> s;
    for(int i = 0; i < k; i ++) {
        s.insert({a[ord[i]], ord[i]});
        v1 += a[ord[i]];
    }
    for(int i = k; i < n; i ++) {
        int vb = b[ord[i]], va = a[ord[i]];
        if(vb > va) 
            v2 += vb - va;

    }

    for(int i = k; i < n; i++) {
        res = max(res, v2 - v1);
        // cout << v2 << ' ' << v1 << ' ' << res << endl;

        int vb = b[ord[i]], va = a[ord[i]];
        if(vb > va) 
            v2 -= vb - va;
        s.insert({va, ord[i]});
        v1 += va;
        v1 -= prev(s.end()) -> first;
        s.erase(prev(s.end()));
    }

    cout << res << endl;
}


signed main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}