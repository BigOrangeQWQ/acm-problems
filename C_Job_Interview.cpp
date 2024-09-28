#include <bits/stdc++.h>

#define int long long
#define x first
#define y second

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n + m + 1);
    for(int i = 0; i < n + m + 1;i ++) {
        cin >> p[i].x >> p[i].y;
    }
    int sum1 = 0, sum2 = 0;
    priority_queue<int, vector<int>, greater<int>> q1, q2;
    sort(p.begin() + 1, p.end());
}


signed main() {
    int T;cin >> T;
    while(T--)
        solve();
}