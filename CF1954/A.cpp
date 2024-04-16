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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(m);
    for(int i = 1, cnt = 0; i <= n;i ++) {
        x[cnt] ++; 
        cnt = (cnt + 1) % m;
    }
    sort(x.begin(), x.end());
    if(k < n - x.back()) {
        cout << "YES" << endl;
    }
    else 
        cout << "NO" << endl;
}

void solve2() {
    int n, m, k;
    cin >> n >>m >> k;
    if((n + m - 1) / m + k >= n)
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}