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
    string x, y;
    cin >> x >> y;
    if(x < y) swap(x, y); 
    for(int i = 0; i < x.length();i ++) {
        if(x[i] > y[i]) {
            for(int j = i + 1; j < x.length(); j++) {
                if(x[j] > y[j])
                    swap(x[j], y[j]);
            }
            break;
        }
    }
    cout << x << endl << y << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}