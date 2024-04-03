#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<PII> p(m);
    vector<int> ans(n + 1);
    for(int i = 0; i < m; i++) {
        // cin >> p[i].x >> p[i].y;
        int x, y;
        cin >> x >> y;
        p[i].x = min(x, y), p[i].y = max(x, y);
    }

    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= 4; j++){
            bool flag = true;
            for(int k = 0; k < m && flag; k++) {
                if(p[k].first == i  && ans[p[k].second] == j) {
                    //cout << i << ' ' << j << ' ' << ans[p[k].second] << endl;
                    flag = false;
                    break;
                }   
                if(p[k].second == i && ans[p[k].first] == j) {
                    //cout << i << ' ' << j << ' ' << ans[p[k].first] << endl;
                    flag = false;
                    break;
                }
            }
            //cout <<"flag" << flag << ' ' << i << ' ' << j << endl;
            if(flag){
                ans[i] = j; 
                break;
            }
        }
    }
    for(int i = 1; i <= n ; i++)
        cout << ans[i];
    cout << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}