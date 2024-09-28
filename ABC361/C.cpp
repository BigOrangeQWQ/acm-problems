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
// #define int long long

using PII = pair<int, int>;

using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n;i ++) 
        cin >> p[i];
    sort(p.begin(),p.end());
    int ans = p[n - 1] - p[0];
    for(int i = 0; i <= k ; i ++) {
        // cout << i + n - k - 1 << ' ' << i << endl;
        // cout << p[i + n - k - 1] << ' ' << p[i] << endl;

        ans = min(ans, p[i + n - k - 1] - p[i]);
        // cout << ans << endl;
    }
    cout << ans << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}