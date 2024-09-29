#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MOD =  998244353;

void solve() {
    string v;
    cin >> v;
    vector<bool> p;
    for(auto c: v) 
        p.push_back(c == '1' ? true : false);
    
    int res = 1, cnt = 0, n = p.size();
    for(int i = 0; i < n; i++) {
        int cc = 0;
        while(p[i] == p[i + 1] && i < n - 1) {
            cc ++;
            i ++;
        }
        cnt += cc;
        res *= cc + 1;
        res %= MOD;
    }
    for(int i = 1; i <= cnt; i++) {
        res *= i;
        res %= MOD;
    }
    cout << cnt << ' ' <<  res % MOD << endl;
}

signed main() {
    int T;cin >> T;
    while(T--)
        solve();
}