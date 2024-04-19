#include <iostream>
#include <vector>


#define x first
#define y second
#define int LL

using namespace std;
using LL = long long;
using PII = pair<int,int>;

void solve() {
    int n, q;
    cin >> n;
    vector<int> p(n + 1), s(n + 1);
    for(int i = 1; i <= n;i ++)
        cin >> p[i], s[i] = s[i - 1] + p[i];
    
    cin >> q;
    while(q--) {
        int l, u;
        cin >> l >> u;

        auto res =[&](int r) {
            int t = s[r] -  s[l - 1];
            return (u + (u - t + 1)) * t / 2;
        };

        int al = l, ar = n;
        while(al + 1 < ar) {
            int mid = (al + ar) >> 1;
            if(s[mid] - s[l - 1] <= u) al = mid;
            else ar = mid;
        }

        PII ans = {-1e18, 0};
        // cout << max(al - 2, l) << ' ' << min(al + 2, n) << endl;
        for(int i = max(al - 2, l); i <= min(al + 2, n);i ++) {
            if(res(i) > ans.x) 
                ans = {res(i), i};
        }
        cout << ans.y << ' ';
        // cout << l << ' ' << u << endl;
        // if()
        // cout << al << ' '; 
        

    }
    cout << endl;
    
}
//0 1 3 4 


signed main() {
    int T;cin>>T;
    while(T--> 0) {
        solve();
    }
}