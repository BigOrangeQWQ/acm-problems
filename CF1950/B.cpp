#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<string> v;
    v.push_back("##");
    v.push_back("..");
    
    for(int i = 1; i <= n;i ++) {
        string ans = "";
        for(int j = 1; j <= n; j++) {
            ans += v[(i + j)% 2];
        }
        cout << ans << endl;
        cout << ans << endl;
    }

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}