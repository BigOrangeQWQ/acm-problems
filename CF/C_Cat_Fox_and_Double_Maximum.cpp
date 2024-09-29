#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1), res(n + 1);
    set<int> tag;
    int loc;
    for(int i = 1; i <=n ;i ++) {
        cin >> p[i];
        tag.insert(i);
        if(p[i] == 1)
            loc = i;
    }
    if(loc & 1) {
        for(int i = 2; i <= n - 2;i += 2) {
            res[i] = n - p[i] + 2;
            tag.erase(n - p[i] + 2);
        }
    }
    else {
        for(int i = 3; i <= n - 1;i += 2) {
            res[i] = n - p[i] + 2;
            tag.erase(n - p[i] + 2);
        }
    }

    for(int i = 1; i <= n;i ++) {
        if(p[i] == 1 || res[i])
            continue;
        auto it = tag.upper_bound(n - p[i] + 1);
        it --;
        res[i] = *it;
        tag.erase(it);
    }
    for(auto i: tag){
        res[loc] = i;
        break;
    }
    for(int i = 1; i <= n;i ++)
        cout << res[i] << " \n"[i == n];
}
int main() {
    int T;cin >> T;
    while(T--)
        solve();
}