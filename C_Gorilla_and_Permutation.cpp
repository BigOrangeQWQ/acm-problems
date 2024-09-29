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
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> flag(n + 1);
    vector<int> ans(n + 1);
    for(int i = n - m + 1, v = 1; i <= n;i ++, v++) {
        ans[i] = v;
        flag[v] = true;
    }
    for(int i = 1, v = n; i <= n - m; i ++) {
        ans[i] = v--;
    }
    // for(int i = n, v = 1; i >= 1 || v <= n; i --) {
    //     if(!flag[v]){
    //         ans[v] = i;
    //         v++;
    //         flag[i]=true;
    //     }
    // }
    for(int i = 1;i <=n ;i++)
        cout << ans[i] << " \n"[i == n];
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}