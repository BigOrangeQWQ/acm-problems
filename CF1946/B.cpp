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

int mod(int x, int p) {
    int q = x / p;
    if(x % p != 0)
        q--; 

    //cout << x << 'v' << q << 'x' << endl;
    return x - q * p;
}
void solve() {
    int n, k, sumc = 0;
    int MOD = 1e9+7;
    cin >> n >> k;
    vector<int> p(n + 1), dp(n + 1);
    for(int i = 1; i <= n ;i ++) {
        cin >> p[i];
        sumc += p[i];
    }
    int res = 0;
    for(int i = 1; i <= n;i ++) {
        dp[i] = max(dp[i - 1] + p[i], 0ll);
        res = max(res, dp[i]);
    }
    

    for(int i = 1;i <= k; i++) {
        sumc += res;
        res *= 2;
        res %= MOD;
        // res = mod(res, MOD);

    }
    if(sumc < 0)
        cout <<  mod(sumc, MOD)  << endl;
    else 
        cout << sumc % MOD << endl;
    //cout << mod(sumc, MOD) % MOD << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}