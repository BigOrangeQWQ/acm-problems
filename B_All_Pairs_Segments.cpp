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
    cin >> n >> k;
    map<int, int> mp;

    vector<int> p(n + 1), q(k + 1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> q[i];
    }
    for (int i = 1; i <= n; i++) {
        int cnt = (n - i) + (n - i + 1) * (i - 1);
        mp[cnt]++;
    }
    for (int i = 1; i < n; i++) {
        int cnt = i * (n - i);
        mp[cnt] += p[i + 1] - p[i] - 1;
    }

    for (int i = 1; i <= k; i++) {
        cout << mp[q[i]] << " \n"[i == k];
    }
}

signed main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}
