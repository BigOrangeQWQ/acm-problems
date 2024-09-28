#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

// 所做的操作是将某一部分的数轴翻折过去，
// 那么贪心的升序排序，从小翻折到大(结果为辗转相除法 gcd)
// 可得折纸的最小极差


int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n ;i++)
        cin >> p[i];
    sort(p.begin(),p.end());
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans = gcd(p[i] - p[i - 1], ans);
    }
    cout << ans << "\n";
}
signed main() {
    int T;cin >> T;
    while(T--) {
        solve();
    }
}