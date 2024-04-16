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
    int k, q;
    cin >> k >> q;
    int mq = 1e9;
    for(int i = 0;i < k; i++) {
        int v;cin >> v;
        mq = min(v, mq);
    }
    for(int i = 1; i <= q;i ++) {
        int n; cin >> n;
        if(n >= mq) 
            cout << mq - 1 << " \n"[i == q];
        else 
            cout << n << " \n"[i == q];
    }
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}