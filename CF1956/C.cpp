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
    int n; cin >> n;
    int res = 0;
    for(int i = 1; i <= n;i ++) {
        for(int j = 1; j <= n;j ++) {
            res += max(i, j);
        }
    }
    cout << res << " " << 2 * n << endl;

    for(int i = n; i >= 1; i --) {
        cout << 1 << ' ' << i << ' ';
        for(int i = 1; i <= n;i ++)
            cout << i << " \n"[i == n];

        cout << 2 << ' ' << i << ' ';
        for(int i = 1; i <= n;i ++)
            cout << i << " \n"[i == n];
    }
}

signed main() {
    cin.tie(nullptr) -> 
        ios::sync_with_stdio(false);
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}