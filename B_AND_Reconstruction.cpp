#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    n --;
    for(int i = 0; i < n; i ++)
        cin >> p[i];

    vector<int> ans(n + 1);
    ans[0] = p[0];
    ans[n] = p[n - 1];
    for(int i = 1; i < n;i ++) {
        ans[i] = p[i] | p[i - 1];
        // cout << 'x' << i << ' ' << i << ' ' << i + 1 << endl;
    }
    // for(int i = 0; i <= n ;i ++) {
    //     cout << ans[i] << " \n"[i == n];
    // }
    for(int i = 1; i <= n; i++) {
        if((ans[i] & ans[i - 1]) != p[ i - 1]) {
            cout << "-1\n";
            return;
        }
    }
    for(int i = 0; i <=n ;i ++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    int T; cin >> T;
    while(T--){
        solve();
    }
}
