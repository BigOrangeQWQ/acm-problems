#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), cnt(500);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        cnt[p[i]] ++;
        if(cnt[p[i]] >= k) {
            flag = true;
        }
    }
    if(flag)
        cout << k - 1 << endl;
    else 
        cout << n << endl;
}

int main() {
    int T;cin >> T;
    // solve() 
    while(T--)
        solve();
}