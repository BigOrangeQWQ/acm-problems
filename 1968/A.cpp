#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <deque>
#include <numeric>

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;

using LL = long long;

void solve() {
    int x; 
    cin >> x;
    int res = 0, ans;
    for(int i = 1; i < x; i ++) {
        if((gcd(i, x) + i) >= res) {
            res = gcd(i, x) + i;
            ans = i;
        }
    }
    cout << ans << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}