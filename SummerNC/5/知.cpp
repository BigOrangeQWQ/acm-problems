#include <bits/stdc++.h>

using namespace std;

using ll = long long;


void solve() {
    auto binpow = [&](ll a, ll b, ll p) {
        a %= p;
        ll res = 1;
        while(b) {
            if(b & 1) res = a * res % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    };

    int n; cin >> n;
    vector<int> p(n);
    ll sumx = 0;
    for(int i = 0; i < n; i ++)
        cin >> p[i], sumx += p[i];
    sumx /= n;

    using pii = pair<int,int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    set<int> Q;

    auto work = [&](int a, int b) {
        
    };
    for(int i = 0; i < n;i ++) {
        if(p[i] > sumx)
            Q.insert(i);
        else 
            q.push({p[i], i});
    }



}

int main() {
    int T;cin >> T;
    while(T--) {
        solve();
    }
}