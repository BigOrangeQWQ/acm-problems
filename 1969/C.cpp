#include <bits/stdc++.h>

using namespace std;

#define int long long
const int inf = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, inf)); //n k^2
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j ++) {
            int v = p[i];
            for(int d = 0; d + j <= k && i + d < n; d ++) {
                v = min(p[d + i], v);
                dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d],
                                                dp[i][j] + (d + 1) * v);
            }
        }
    }
    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
}

signed main() {
    int T;cin >> T;
    while(T--) 
        solve();
}



// void solve() {
//     int n, k;
//     cin >> n >> k;
//     vector<int> p(n + 1);
//     // vector<pair<int, int>> q;
//     using PII = pair<int,int>;
//     priority_queue<PII, vector<PII>> q;
//     int res = 0;
//     for(int i = 1; i <= n; i++) {
//         cin >> p[i];
//         res += p[i];
//         q.push({p[i], i});
//     }
//     // sort(q.begin(), q.end(), greater<pair<int,int>>());
//     for(int i = 1; i <= k; i++) {
//         int x = q.top().second; q.pop();
//         // cout << x << endl;
//         int v = p[x];
//         if(x > 1)
//             v = min(v, p[x - 1]);
//         if(x < n)
//             v = min(v, p[x + 1]);
//         // cout << p[x] - v << endl;
//         res -= p[x] - v;
//         p[x] = v;
//         q.push({p[x], x});
//     }
//     cout << res << endl;
// }
