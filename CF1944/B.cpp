#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
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


//尽量为其数组里相同的数字，
//若没有相同则，数字一样，可以直接取出
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), aa, bb;
    map<int, int> ac, bc;
    for(int i = 0; i < n; i++) {
        cin >> a[i], ac[a[i]]++;
        if(ac[a[i]] >= 2)
            aa.push_back(a[i]);
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i], bc[b[i]]++;
        if(bc[b[i]] >= 2)
            bb.push_back(b[i]);
    }

    vector<int> ans1, ans2;
    for(int i = 1; i <= k; i++) {
        if(aa.size()){
            ans1.push_back(aa.back());
            ans1.push_back(aa.back());
            aa.pop_back();
            ans2.push_back(bb.back());
            ans2.push_back(bb.back());
            bb.pop_back();
        }
        else {
            // cout <<'k' <<  a.back() << endl;
            while (ac[a.back()] >= 2) 
                a.pop_back();

            ans1.push_back(a.back());
            ans2.push_back(a.back());
            a.pop_back();

            while (ac[a.back()] >= 2) 
                a.pop_back();
            ans1.push_back(a.back());
            ans2.push_back(a.back());
            a.pop_back();
        }
    }
    for(int i = 0; i < ans1.size(); i++) {
        cout << ans1[i] << " \n"[i == ans1.size() - 1];
    }
    for(int i = 0; i < ans2.size(); i++) {
        cout << ans2[i] << " \n"[i == ans2.size() - 1];
    }
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}