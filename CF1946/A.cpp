#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>



using namespace std;

#define x first
#define y second
#define endl '\n'
#define int long long

using PII = pair<int, int>;

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> p[i];
    
    sort(p.begin() + 1, p.end());
    int mid = (n + 1) / 2;
    int res = 1;
    for(int i = mid+1; i <= n; i++) {
        if(p[i] == p[mid])
            res++;
    }
    cout << res << endl;

}
// 4 5 6 6 6

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}