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
    int n, k, x, v;
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++) {
        cin >> v;
        cout << v << ' ';
        if(k == i + 1) 
            cout << x << ' ';
    }
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}