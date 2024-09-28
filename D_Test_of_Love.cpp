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
    string c, v;

    cin >> n >> m >> k;
    cin >> c;
    v = " " + c;
    int INF = (1 << 30);

    vector<int> cnt(n + 10, INF);
    cnt[0] = 0;
    for(int i = 1;i <= n + 1; i++) {
        if(v[i] == 'C')
            continue;
        if(v[i - 1] == 'W')
            cnt[i] = min(cnt[i], cnt[i - 1] + 1);
        for(int j = 1; j <= m;j ++) {
            if(i - j >= 0 && (v[i - j] == 'L' || i - j == 0) && cnt[i - j] != INF ){
                cnt[i] = min(cnt[i], cnt[i - j]);
            }
        }
    }
    int ans = false;
    if(cnt[n + 1] != INF && cnt[n + 1] <= k)
        ans = true;
        
    cout << (ans ? "YES" : "NO") << endl;
} 

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}