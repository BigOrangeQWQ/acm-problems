#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n ;i ++)
        cin >> p[i];
    int ans = p[0];
    for(int i = 0; i < n; i += 2)
        ans = max(ans, p[i]);
    cout << ans << '\n';
}

int main() {
    int T;cin >> T;
    while(T--)
        solve();
}