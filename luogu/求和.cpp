#include <iostream>

#define endl '\n'
using namespace std;
using LL = long long;

LL binpow(int a, int b, int p) {
    int res = 1;
    while(b) {
        if(b & 1) 
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res % p;
}

const int MOD = 1e4;
int sum[MOD + 10];

void solve() {
    LL a, b;
    cin >> a >> b;
    for(int i = 1; i <= 10000; i++) {
        sum[i] = (sum[i - 1] + binpow(i, b, MOD)) % MOD;
    }
    LL ans = (a / MOD * sum[MOD] + sum[a % MOD]) % MOD;
    cout << ans << endl;
}

int main() {
    int T;cin >> T;
    while(T--) {
        solve();
    }
}