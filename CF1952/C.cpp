#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    for(int i = 1; i <= n;i++) {
        cin >> p[i];
    }
    int left = (m + 1) / 2;
    int right = m / 2;
    int res = 0;
    for(int i = 1, j = n;;) {
        if(p[i] <= left && i < j)
            left -= p[i], res++, i ++;
        if(p[j] <= right && i < j)
            right -= p[j], res++, j --;
        if(i == j) {
            if(p[i] <= left + right){
                res++;
            }
            break;
        }
        if(p[i] > left && p[j] > right)
            break;
    }
    cout << res << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}