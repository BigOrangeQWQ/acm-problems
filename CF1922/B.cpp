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

int ans1(int x) {
    return x * (x - 1) / 2;
}

int ans2(int x) {
    return x * (x - 1) * (x - 2) / 6;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1), cnt(n + 1), sumx(n + 1);
    for(int i = 1; i <= n;i ++){
        cin >> p[i];
        cnt[p[i]] ++;
    }
    sumx[0] = cnt[0];
    for(int i = 1; i <= n;i ++) {
        sumx[i] = sumx[i - 1] + cnt[i];
    }
    int res = 0;
    for(int i = 0; i <= n;i ++) {
        // if(cnt[i]) {
        if(i != 0)
            res += ans1(cnt[i]) * sumx[i - 1] + ans2(cnt[i]);
        else
            res += ans2(cnt[i]);
            // if(cnt[i] >= 3)
            // res += ans2(cnt[i]) ;
        // }
    }

    cout << res << endl;
}

//[3 7]
//

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}