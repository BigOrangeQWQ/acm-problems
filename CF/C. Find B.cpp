#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n, q;
    cin >> n >> q;
    // 原数组， 原数组前缀和
    // 构造数组的最小值前缀和。
    // 1 -> 2
    // 1..n -> 1
    vector<int> p(n + 1), qzh(n + 1), res(n + 1);
    for(int i = 1; i <= n;i ++) {
        cin >> p[i];
        qzh[i] = qzh[i - 1] + p[i];
        res[i] = res[i - 1] + 1 + (p[i] == 1);
    }
    while(q --) {
        int l, r;
        cin >> l >> r;
        if(r - l == 0) {
            cout << "NO" << endl;
            continue;
        }
        int sump = qzh[r] - qzh[l - 1];
        int resp = res[r] - res[l - 1];
        if(sump < resp) 
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin >>T;
    while(T--)
        solve();
}