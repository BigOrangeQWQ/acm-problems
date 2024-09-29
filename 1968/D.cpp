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

const int N = 2e5 + 10;
int dp1[N], dp2[N];

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<int> p(n + 1), v(n + 1);
    for(int i = 0; i < n; i++) 
        cin >> p[i];
    for(int i = 0; i < n; i ++)
        cin >> v[i];
    auto func = [&](int loc) {
        loc--;
        int res = 0, sumx = 0;
        for(int i = 0; i < n && i < k; i ++, loc = p[loc] - 1) {
            res = max(res, sumx + (k - i) * v[loc]);
            sumx += v[loc];
        }
        return res;
    };
    int va = func(a), vb = func(b);
    if(va > vb) {
        cout << "Bodya" << endl;
    }
    else if(va < vb) {
        cout << "Sasha" << endl;
    }
    else 
        cout << "Draw" << endl;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}