#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n + 1), res;
    for(int i = 1; i <= n; i ++ ) {
        cin >> p[i];
    }

    res.push_back(1);
    int l = 1, r = n + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(p[mid] <= x) 
            l = mid, res.push_back(mid);
        else 
            r = mid;
    }
    int cnt = find(p.begin() + 1, p.end(), x) - p.begin();
    if(cnt == res.back())
        cout << 0 << endl;
    else {
        cout << 1 << endl;
        cout << res.back() << ' ' <<  cnt << endl;
    }
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}