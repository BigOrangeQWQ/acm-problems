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
    int n;cin >> n;
    vector<int> p(n + 1);
    int res = 0;
    for(int i = 1; i <= n ;i ++) {
        int x;cin >> x;
        p[x] += 1;
        if(p[x] >= 2)
            res ++;
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