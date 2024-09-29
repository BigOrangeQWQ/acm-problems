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
    int n, k;
    cin >> n >> k;
    vector<int> q(n);
    for(int i = 0; i < n;i ++) {
        cin >> q[i];
    }
    sort(q.begin(), q.end(), greater<int>());
    int w = q.back(), cnt = 1;
    q.pop_back();
    while(q.size() && q.back() == w) 
        q.pop_back(), cnt++;
    while(q.size()) {
        int w2 = q.back();
        // cout << w2 << ' ' << w << ' ' << cnt << endl;
        if((w2 - w) * cnt > k)
            break;
        // cout << 111 << endl;
        k -= (w2 - w) * cnt;
        w = w2;
        // cout << w << ' ' << k << endl;
        while(q.size() && q.back() == w) 
            q.pop_back(), cnt++;
    }
    // cout << k << endl;
    w += k / cnt;
    k %= cnt;
    cnt -= k;
    // cout << w << ' ' << cnt << endl;
    cout <<  n * w - cnt + 1LL << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}