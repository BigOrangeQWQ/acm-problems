#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <deque>

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

void solve() {
    int n, m ,k, res = 0;
    cin >> n >> m >> k;
    vector<int> p(n + 1);
    vector<int> q(m + 1);
    map<int, int> qs, now; //q数组里的数
    // set<int> cnt; //数字x满足了
    int cnt = 0;
    for(int i = 1; i <= n;i ++) {
        cin >> p[i];
        qs[p[i]] = 0;
    }

    for(int i = 1;i <= m;i ++) {
        cin >> q[i];
        qs[q[i]]++;
    }

    for(int i = 1; i <= m; i++) {
        if(qs[p[i]] > 0 && qs[p[i]] > now[p[i]]) 
            cnt ++;
        now[p[i]]++;
    }
    
    if(cnt >= k)
        res++;
    for(int i = m + 1; i <= n; i ++) {
        now[p[i - m]] --;
        if(qs[p[i - m]] > 0 && now[p[i - m]] < qs[p[i - m]]){
            cnt --;
        }

        if(qs[p[i]] != 0 && qs[p[i]] > now[p[i]]) 
            cnt++;
        now[p[i]]++;

        if(cnt >= k)
            res++;
    }
    cout << res << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}