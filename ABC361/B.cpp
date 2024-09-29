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
    int a1,b1,c1,d1,e1,f1;
    int a2,b2,c2,d2,e2,f2;
    cin >> a1 >> b1 >> c1 >> d1 >> e1 >> f1;
    cin >> a2 >> b2 >> c2 >> d2 >> e2 >> f2;
    if(a1 > a2) {
        swap(a1,a2);
    }
    if(b1 > b2) {
        swap(b1, b2);
    }
    if(c1 > c2)
        swap(c1, c2);
    if(
        // (a1 <= a2 && a2 < d1 && b1 <= b2 && b2 < e1 && c1 <= c2 && c2 < f1) 
        (min(d1,d2) > max(a1, a2) && min(e1,e2) > max(b1,b2) && min(f1,f2) > max(c1,c2))
    )
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}