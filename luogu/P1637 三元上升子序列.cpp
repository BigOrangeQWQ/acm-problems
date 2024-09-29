#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <deque>
#include <unordered_map>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

unordered_map<int, int> mp; //离散化

using PII = pair<int, int>;

using LL = long long;

// const int N = 1e5 + 10;

struct Fenwick {
    vector<int> a;
    int n;
    
    Fenwick(int n_ = 0) {
        n = n_;
        a = vector<int> (n_);
    }

    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int x, int v) {
        for(int i = x; i <= n; i += lowbit(i))
            a[i] = a[i] + v;
    } 
    
    int getSum(int x) {
        int res = 0;
        for(int i = x; i > 0;i -= lowbit(i)) {
            res += a[i];
        }
        return res;
    }

    int rangeSum(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }
};


void solve() {
    int n; cin >> n;
    Fenwick minx(n + 10), maxv(n + 10);
    vector<int> a(n + 1), a_(n + 1), l(n + 1), r(n + 1);
    for(int i = 1; i <= n;i ++) {
        cin >> a[i];
        a_[i] = a[i];
    }
    sort(a_.begin() + 1, a_.end());
    for(int i = 1, cnt = 1; i <= n; i ++) {
        if(mp.find(a_[i]) == mp.end()){
            mp[a_[i]] = cnt++;
        }
    }

    for(int i = 1; i <= n; i++) {
        minx.add(mp[a[i]], 1);
        l[i] = minx.getSum(mp[a[i]] - 1);
    }
    for(int i = n; i >= 1; i--) {
        maxv.add(mp[a[i]], 1);
        // cout << mp[a[i]] << ' ' << i << ' ' << maxv.getSum(mp[a[i]]) << endl;
        r[i] = n - i - (maxv.getSum(mp[a[i]]) - 1);
    }
    int res = 0;
    for(int i = 2; i < n; i++) {
        res += l[i]*r[i];
        // cout << l[i] << ' '  <<  r[i] << endl;
    }
    cout << res << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}