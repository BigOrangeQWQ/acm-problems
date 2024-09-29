#include <bits/stdc++.h>

using namespace std;


//给定n个数，划出k个区间，区间每个值都相等则答案加一

int gcd(int x, int y) {
    if(y == 0)
        return x;
    return gcd(y, x % y);
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0 ; i < n; i++) {
        cin >> p[i];
    }

    int res = 0;
    for(int k = 1; k <= n; k ++) {
        if(n % k == 0) {
            int flag = 0;
            // cout << '\n';
            for(int i = 0; i + k < n; i ++) {
                // cout << i << ' ' << i + k << '\n';
                flag = gcd(flag, abs(p[i] - p[i + k]));
            }
            res += (flag != 1);
        }
    }
    cout << res << '\n';
}

int main() {
    int T;cin >> T;
    while(T--)
        solve();
}