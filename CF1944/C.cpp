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

// void solve() {
    // int n, maxx = 0; cin >> n;
    // vector<int> p(2e5 + 1);
    // for(int i = 1; i <= n;i ++) {
    //     int x; cin >> x;
    //     p[x] ++ ;
    //     maxx = max(x , maxx);
    // }
    // int res = maxx + 1;
    // for(int i = 0; i <= maxx;i ++) {
    //     if(p[i] <= i){
    //         res = i;
    //         break;
    //     }
    // }
    // cout << res << endl;
// }

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n;i ++) {
        int x; cin >> x;
        p[x] ++;
    }
    int v = 0;
    for(int i = 0; i <= n; i ++) {
        v += (p[i] ==  1);
        if((v == 2) || p[i] == 0) {
            cout << i << endl; 
            break;
        } 
    }
    return;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}