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

// int sum = 0;
vector<pair<int,int>> p(114514);
int n, ans = 288888888;

void dfs(int cur, int ku, int suan, int s) {
    // if(ku != 0 || suan != 0) 
    // cout << cur << ' ' << ku << ' ' << suan << ' ' << s  << endl;

    if(cur >= n){ 
        if(s >= 1)
            ans = min(ans, abs(ku - suan));
        return;
    }
    dfs(cur + 1, ku + p[cur + 1].second, suan * p[cur + 1].first, s + 1);
    dfs(cur + 1, ku, suan, s);
}


void solve() {
    cin>>n;

    for(int i= 1;i <= n;i++){
        cin >> p[i].first >> p[i].second;
    }
    dfs(0, 0, 1, 0);
    cout << ans << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}