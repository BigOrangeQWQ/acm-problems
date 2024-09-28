#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end(), greater<int>());
    int sumc = accumulate(p.begin(), p.end(), 0LL);
    int maxx = *max_element(p.begin(), p.end());
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int x = max(maxx * i, (sumc + i - 1) / i * i);
        // 最大的数 * i组 = 分 i 组所需的基础卡片数 和 满足
        // sum/i 向上取整 * i 为分该组所需的数目的最大值的计算结果
        if (x <= sumc + k) {
            res = max(i, res);
        }
    }
    cout << res << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}