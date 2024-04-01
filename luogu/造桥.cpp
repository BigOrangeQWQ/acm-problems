#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define int long long

using namespace std;

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    d++;
    vector<int> cost(n);
    for(int i = 0; i < n; i ++) {
        vector<int> a(m), dp(m, 1e18);
        deque<int> q;
        for(int j = 0; j < m;j ++) {
            cin >> a[j];
            a[j] ++;
        }
        dp[0] = 1;
        for(int j = 1; j < m; j ++) {
            while(q.size() && dp[q.back()] > dp[j - 1])
                q.pop_back();
            q.push_back(j - 1);
            while(q.size() && q.front() < j - d) 
                q.pop_front();
            dp[j] = dp[q.front()] + a[j];
        }
        cost[i] = dp[m - 1];
    }

    // sort(cost.begin(), cost.end());
    // int res = 0;
    // for(int i = 0; i < k; i++)
    //     res += cost[i];
    
    // cout << res << '\n';

    int ans =(int) 1e18;
    for (int i = 0; i + k <= n; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += cost[i + j];
            // cout << 's' << i + j << ' ' << cost[i + j] << ' ';
        }
        // cout << endl;
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    // for(int i = 0; i < n; i ++) {
    //     cout << cost[i] << ' ';
    // }
    // cout << endl;
}

signed main() {
    int T;
    cin >> T;
    while(T --> 0) {
        solve();
    }
}