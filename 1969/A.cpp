#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n ;i++) {
        int x; cin >> x;
        p[x] = i;
    }
    for(int i = 1; i <= n;i ++) {
        if(p[p[i]] == i) {
            cout << 2 << endl;
            return;
        }
    }
    cout << 3 << endl;
}


int main() {
    int T;cin >> T;
    while(T--)
        solve();
}