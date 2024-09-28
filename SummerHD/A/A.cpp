#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct strHash {
    using ll = long long;

    const int BASE1 = 29, MOD1 = 1e9 + 7;
    const int BASE2 = 131, MOD2 = 1e9 + 9;

    int n;
    string s;
    vector<int> ha1, ha2;
    vector<int> p1, p2;

    strHash();

    strHash(string _s) {
        s = ' ' + _s;
        n = _s.length();

        ha1 = vector<int>(n + 5), ha2 = vector<int>(n + 5);
        p1 = vector<int>(n + 5), p2 = vector<int>(n + 5);

        p1[0] = p2[0] = 1;
        for(int i = 1; i <= n;i ++) {
            p1[i] = (ll)p1[i - 1] * BASE1 % MOD1;
            p2[i] = (ll)p2[i - 1] * BASE2 % MOD2;
        }

        hash();
    };

    void hash() {
        for (int i = 1; i <= n; i++) {
            ha1[i] = ((ll)ha1[i - 1] * BASE1 % MOD1 + s[i]) % MOD1;
            ha2[i] = ((ll)ha2[i - 1] * BASE2 % MOD2 + s[i]) % MOD2;
        }
    }

    pair<int, int> get(int l, int r) {
        int res1 = ((ha1[r] - (ll)ha1[l - 1] * p1[r - l + 1] % MOD1) % MOD1 + MOD1) % MOD1;
        int res2 = ((ha2[r] - (ll)ha2[l - 1] * p2[r - l + 1] % MOD2) % MOD2 + MOD2) % MOD2;
        return pair<int, int>(res1, res2);
    }
};

void solve() {
    string v, t;
    cin >> v >> t;
    int la = v.length();

    v = v + v;

    strHash s1 = strHash(v);
    set<pair<int, int>> hs;
    for(int i = 0; i < v.length(); i++) {
        hs.insert(s1.get(i + 1, i + la));
    }

    strHash s2 = strHash(t);
    int ans = 0;
    for(int i = 0; i + la <= t.length(); i ++) {
        auto hb = s2.get(i + 1, i + la);
        if(hs.find(hb) != hs.end()) {
            ans ++ ;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    int T;cin >> T;
    while(T--)
        solve();
}

// void solve() {
//     // string v, t;
//     // cin >> v >> t;
//     // unordered_set<string> tmp;

//     // int ans = 0;
//     // int vsiz = v.length();
//     // v = v + v;
//     // for(int i = 0; i < vsiz; i ++) {
//     //     tmp.insert(v.substr(i, vsiz));
//     // }
//     // for(int i = 0; i < t.size(); i++) {
//     //     if(tmp.find(t.substr(i, vsiz)) != tmp.end()) {
//     //         ans ++;
//     //     }
//     // }
//     // cout << ans << endl;
// }

// int main() {
//     ios::sync_with_stdio (false);
//     cin.tie (nullptr);

//     int T;cin >> T;
//     while(T--)
//         solve();
// }