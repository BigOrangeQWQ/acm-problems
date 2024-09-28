#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <deque>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

using PII = pair<int, int>;

using LL = long long;

void solve() {
    int n;cin >> n;
    vector<int> p(n + 10), res(n + 10);
    for(int i = 0 ; i < n - 1; i ++) {
        cin >> p[i];
    }
    res[0] = p[0] + 1;
    for(int i = 1; i < n; i ++){
        int k = 1;
        if(p[i] > res[i - 1])
            k = p[i] / res[i - 1];
        for(int j = k; j <= k + 10;j ++) {
            int v = res[i - 1] * j + p[i - 1] ;
            // cout << i << ' ' << v << ' ' << res[i - 1] << ' ' <<  v % max(res[i - 1], 1LL) << endl;
            if(v % max(res[i - 1], 1LL) == p[i - 1] && v > p[i]) {
                res[i] = v;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << " \n"[i == n - 1];
    }
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}