#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;

using LL = long long;

void solve() {
    priority_queue<int> ans;
    priority_queue<int, vector<int>, greater<int>> pass;

    int n, k, cnt = 0;
    cin >> n >> k;
    queue<int> p;
    vector<int> c(k);

    for(int i = 0; i < n;i ++){
        int x; cin >> x;
        p.push(x);
    }
    for(int i = 0; i < k;i ++)
        cin >> c[i];
    
    ans.push(p.front());p.pop();
    for(auto x: c) {
        cnt ++ ;

        while(ans.size() + pass.size() < x) {
            int v = p.front(); p.pop();
            if(v > ans.top())
                pass.push(v);
            else 
                ans.push(v);
        }

        while(ans.size() > cnt) {
            pass.push(ans.top());
            ans.pop();
        }

        while(ans.size() < cnt) {
            ans.push(pass.top());
            pass.pop();
        }

        cout << ans.top() << endl;
    }


}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}