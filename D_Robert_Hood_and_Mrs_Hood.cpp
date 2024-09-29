#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> p(n + 2);
    for(int i = 1; i <= k; i++) {
        int l, r;
        cin >> l >> r;
        p[max(1, l - d + 1)] ++, p[min(n - d + 1, r) + 1]--;
    }

    // 2 2 2 1 1
    // 3 3 3 2 2 
    int now = 0;
    int v1 = -1, v2 = 1e9;
    int res1 = 0, res2 = 0;

    for(int i = 1; i < n - d + 2;i ++) {
        now += p[i];
        // cout << now << " \n"[i == n - d + 1];
        if(now > v1) {
            v1 = now;
            res1 = i;
        }
        if(now < v2) {
            v2 = now;
            res2 = i;
        }
    }
    cout << res1 << ' ' << res2 << endl;
}

int main() {
    int T;cin >> T;
    while(T-->0) {
        solve();
    }
}


