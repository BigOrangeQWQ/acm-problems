#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using LL = long long;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i <n ;i ++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(),p.end()) - p.begin());
    int res = 0, ptr = 0;
    for(int i = 0; i < p.size();i ++) {
        while(p[i] - p[ptr] >= n) {
            ptr++;
        }
        res = max(res, i - ptr + 1);
    }
    cout << res << endl;
}

signed main() {
    int T;cin>> T;
    while(T --> 0) {
        solve();
    }
}