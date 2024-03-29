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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        // a[i] += a[i - 1];
    }
    for(int i = 1; i<= n ; i++) {
        cin >> b[i];
        b[i] = min(b[i], a[i]);
        b[i] += b[i - 1];
    }

    int res = 1E18;
    for(int i = 1; i <= m; i++) {
        res = min(res, a[i] + b[n] - b[i]);
    }

    cout << res << endl;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}