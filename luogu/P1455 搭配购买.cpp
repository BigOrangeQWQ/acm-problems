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

const int N = 1e5 + 10;
int p[N], cst[N], res[N];

void find() {

}

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    for(int i = 1; i <= n;i ++) {
        cin >> cst[i] >> res[i];
        p[i] = i;
    }

    
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}