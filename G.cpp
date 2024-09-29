#include<iostream>
#define int long long
using namespace std;

int l, r, ans;

void check(int x) {
    if(x < ans) return;
    if((r / x) - ((l - 1) / x) > 1) ans = x;
}

signed main() {
    int T; cin >> T;
    while(T --) {
        cin >> l >> r;
        ans = 1;
        for(int i = 1; i <= 1000000; i ++) {
            // cout << 1 << endl;
            check(i);
            check(r / i);
            check((l - 1) / i);
        }
        cout << ans << endl;
    }
}