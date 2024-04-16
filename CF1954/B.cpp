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
// #define int long long

using PII = pair<int, int>;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    int loc1= 9999999, loc2 = 9999999;
    for(int i = n - 1;i >= 0; i--) {
        if(p[i] != p[0]) 
            loc1 = i;
    }
    for(int i = 0; i < n;i ++) {
        if(p[i] != p[n - 1])
            loc2 = i;
    }
    // cout << loc1 << ' ' <<  loc2 << endl;
    if(loc1 == loc2 && loc1 == 9999999) 
        cout << -1 << endl;
    else 
        cout << min(loc1, loc2) << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}