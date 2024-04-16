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
    int n;
    cin >> n;
    vector<int> p(n + 1), pos;
    p[0] = 0;
    for(int i = 1; i <= n ;i ++) 
        cin >> p[i];
    vector<int> eq(n + 1, p[1]);
    eq[0] = 0;
    if(p == eq) {
        cout << -1 << endl;
        return;
    }

    pos.push_back(0);
    for(int i = 1; i <= n;i ++) {
        if(p[1] != p[i]) {
            pos.push_back(i);
        }
    }
    pos.push_back(n + 1);
    int res = 1e9 + 10;
    for(int i = 0; i < pos.size() - 1; i++) {
        //cout << pos[i + 1] << ' ' << pos[i] << endl;
        res = min(res, pos[i + 1] - pos[i] - 1);
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