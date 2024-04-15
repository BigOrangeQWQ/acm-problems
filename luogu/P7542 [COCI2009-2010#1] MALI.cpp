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
    int n, a, b, amax, amin, bmax, bmin;
    cin >> n;
    cin >> a >> b;
    amax = amin = a;
    bmax = bmin = b;
    cout << a + b << endl;
    // cin >> amax >> amin >> bmax >> bmin;
    // cout << amax + bmax << endl;
    for(int i = 2; i <= n ;i ++) {
        int a, b;
        cin >> a >> b;
        amin = min(a, amin);
        amax = max(a, amax);
        bmin = min(b, bmin);
        bmax = max(b, bmax);
        cout << max(amin +  bmax, bmin + amax) << endl;
    }
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}