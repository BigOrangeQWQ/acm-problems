#include <iostream>
#include <map>
#include <set>
#include <vector>
#define endl '\n'
using namespace std;

void solve() {
    int n, res = 0;
    set<int> w;
    map<int, int> mp;

    cin >> n;
    vector<int> p(n + 5), c(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        c[p[i]] ++;
        w.insert(p[i]);
    }

    for (int i = n; i >= 1; i--) {
        if(mp[p[i]]) {
            mp[p[i]]++;
            continue;
        }
        mp[p[i]]++;
        if (mp.size() == w.size()) {
            res ++;
            for(auto [k ,v]: mp) {
                c[k] -= v;
                if(!c[k]) 
                    w.erase(k);
            }
            mp.clear();
        }
    }

    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T --> 0)
        solve();
}