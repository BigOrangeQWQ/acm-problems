#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
typedef long long int ll;

using namespace std;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

const ll N = 1e6 + 10, INF = 1e9, mod = 998244353;

void solve() {
    ll l, r;
    cin >> l >> r;
    if (r - l == 1) {
        cout << 1 << '\n';
        return;
    }
    ll i;
    // l/k<=g<=r/(k+1)

    for (i = 1;; i++) {
        ll x = r / (i + 1);
        ll y = x * i;
        if (y >= l && y <= r) {
            cout << x << '\n';
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;

    return 0;
}