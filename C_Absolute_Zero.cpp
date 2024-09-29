#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i ++)
        cin >> p[i];

    auto x = set<int>(p.begin(), p.end());
    p = vector<int>(x.begin(), x.end());
    sort(p.begin(),p.end(), greater<int>());
    
    n = p.size();

    if(p.size() == 1) {
        if(p[0] != 0)
            cout << "1\n" << p[0] << "\n";
        else 
            cout << "0\n\n";
        return;
    }

    vector<int> ans;
    int cnt = 0;
    while(x.size() >= 2 && cnt <= 41) {
        auto vx = *max_element(x.begin(), x.end()) + 
                    *min_element(x.begin(),x.end());
        vx /= 2;
        auto y = vector<int>(x.begin(), x.end());
        ans.push_back(vx);
        for(auto &v: y) {
            v = abs(v - vx);
        }
        x = set<int>(y.begin(),y.end());
        cnt ++;
    }

    auto w = vector<int>(x.begin(), x.end());
    ans.push_back(w[0]);
    
    if(ans.size() > 40 || w.size() >= 2) {
        cout << "-1\n";
        return;
    }

    cout << ans.size() << '\n';
    for(int i = 0 ; i < ans.size(); i ++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}