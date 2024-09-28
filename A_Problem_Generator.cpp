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
    int n, m;
    string s;
    vector<int> a(20);
    cin >> n >> m;
    cin >> s;
    int ans = 0;
    for(auto c: s) 
        a[c - 'A'] ++;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 'A' ; j <= 'G';j ++) {
            if(a[j - 'A'])
                a[j - 'A']--;
            else 
                ans ++;
        }
    }
    cout << ans << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}