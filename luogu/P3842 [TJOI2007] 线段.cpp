#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long


void solve() {
    int n;cin >> n;
    vector<pair<int,int>> p(n + 10), dp(n + 10);
    for(int i = 1; i <= n ; i++) {
        cin >> p[i].first >> p[i].second;
    }
    auto dis = [](int a, int b) {return abs(a - b);};

    dp[1].first =dis(1, p[1].second) + dis(p[1].second, p[1].first); // 当前行走完且到达左端点的最短距离
    dp[1].second =  dis(1, p[1].second);  // 当前行走完且到达右端点的最短距离
    for(int i = 2; i <= n; i++) {
        //转移只可能从端点开始
        dp[i].first = min(dp[i - 1].first + dis(p[i - 1].first, p[i].second) + dis(p[i].first, p[i].second),
                            dp[i - 1].second + dis(p[i - 1].second, p[i].second) + dis(p[i].first, p[i].second)) + 1;

        dp[i].second = min(dp[i - 1].first + dis(p[i - 1].first, p[i].first) + dis(p[i].first, p[i].second), 
                            dp[i - 1].second + dis(p[i - 1].second, p[i].first) + dis(p[i].first, p[i].second)) + 1;
    }
    cout << 
        min(
            dp[n].first + dis(p[n].first, n),dp[n].second + dis(p[n].second, n)
        )
    << endl;
}

signed main() {
    int T = 1;
    while(T --> 0) {
        solve();
    }
}


//DP 三要素
//设状态，dp[i][1] 为 走完这一段后右端点所需