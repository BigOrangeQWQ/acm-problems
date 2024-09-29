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
    string a, b, c, t;
    cin >> a >> b >> c;
    for(int i = 0 ; i < n; i ++) {
        if(c[i] != a[i] && c[i] != b[i]) {
            cout << "YES" << endl;
            return;
        }
        if(a[i] == b[i] && b[i] != a[i]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}