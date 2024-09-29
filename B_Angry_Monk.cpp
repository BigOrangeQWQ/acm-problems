#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

using PII = pair<int, int>;

using LL = long long;

void solve() {
    int n, k;
    cin >> k >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int maxv = *max_element(p.begin(), p.end());
    bool flag = false;
    int ans = 0;
    for (auto i : p) {
        if (i == maxv && flag == false) {
            flag = true;
            continue;
        }
        ans += i - 1 + i;
    }
    cout << ans << endl;
}

signed main() {
    int T;
    cin >> T;
    // int T = 1;
    while (T-- > 0) {
        solve();
    }
}