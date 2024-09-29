#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
#define endl '\n'

int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> p(n + 1), d(n + 1);
    for(int i = 1; i <= n ;i ++) 
        cin >> d[i];
    
    for(int i = 1 ;i <= n;i ++) 
        p[i] = d[i] - d[i - 1];

    
    set<int> L, G, E;// less greater equal
    auto update = [&](int i) {
        L.erase(i);
        G.erase(i);
        E.erase(i);
        if(p[i] < 0) 
            L.insert(i);
        else if(p[i] > 0)
            G.insert(i);
        else 
            E.insert(i);
    };

    auto check = [&](int o, int l, int r) {
        if(o == 2) {
            return L.upper_bound(l) == L.lower_bound(r) && G.upper_bound(l) == G.lower_bound(r);
        }
        else if(o == 3) {
            return L.upper_bound(l) == L.lower_bound(r) && E.upper_bound(l) == E.lower_bound(r);
        }
        else if(o == 4) {
            return E.upper_bound(l) == E.lower_bound(r) && G.upper_bound(l) == G.lower_bound(r);
        }
        else if(o == 5) {
            // 非严格递增或递减
            if(E.upper_bound(l) != E.lower_bound(r)) {
                return false;
            }
            auto Gl = G.upper_bound(l);
            auto Gr = G.lower_bound(r);
            auto Ll = L.upper_bound(l);
            auto Lr = L.lower_bound(r);
            // cout << l << ' ' << r << ' ' << *Gl << ' ' << *Gr << endl; 
            if(Gl == Gr || Ll == Lr) 
                return false;
            return *prev(Gr) < *Ll;
        }
        else {
            return false;
        }
    };

    for(int i = 1; i <= n;i ++) 
        update(i);

    int m; cin >> m;
    while(m --) {
        int o, l, r;
        cin >> o >> l >> r;

        // r++;
        if(o == 1) {
            int x; cin >> x;
            p[l] += x;
            p[r + 1] -= x; 
            update(l);
            update(r);
        }
        else {
            cout << check(o, l, r) << endl;
        }
    }
}