#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long


void solve() {
    string s; cin >> s;
    int len = s.length();
    for(int i = len; i >= 1; i --) {
        int cnt = 0;
        for(int j = 0; j + i < len; j++) {
            if((s[j] != '?') && (s[j + i] != '?') && (s[j] != s[j + i]))
                cnt = 0;
            else
                cnt ++;
            if(cnt >= i) {
                cout << 2 * i << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
}

signed main() {
    int T;
    cin >> T;
    // int T = 1;
    while (T --> 0) {
        solve();
    }
}