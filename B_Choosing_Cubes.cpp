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

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> omg(n);
    for(int i = 0; i < n;i ++) {
        cin >> omg[i];
    }
    int fv = omg[f - 1];
    sort(omg.begin(), omg.end(), greater<int>());
    int kv = omg[k - 1]; //数组的边界
    // cout << fv << " " << kv << ' ' << omg[k - 2] << ' ' << omg[k] << endl;
    if(kv == fv && (k < n && omg[k] == fv)) {
        cout << "MAYBE" << endl;
    } 
    else if(fv < kv) {
        cout << "NO" << endl;
    }
    else
        cout << "YES" << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}