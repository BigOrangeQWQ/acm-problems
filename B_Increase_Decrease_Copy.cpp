#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int bn = n + 1;

    vector<int> a(n),b(bn);
    int sum = 1;
    int flag = 2e9+20; //最小的绝对值
    int flag2 = false; //是否相同或在加减的区间里
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < bn ;i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n;i ++) {
        if((b[i] >= b[bn - 1] && a[i] <= b[bn - 1]) || (b[i] <= b[bn - 1] && a[i] >= b[bn - 1])) 
            flag2 = true;
        flag = min(abs(a[i] - b[bn - 1]), flag);
        flag = min(abs(b[i] - b[bn - 1]), flag);
        // cout << abs(a[i] - b[i]) << endl;
        sum += abs(a[i] - b[i]);
    }
    // cout << sum << ' ' << flag << ' ' << flag2 << endl;
    if(flag2)
        cout << sum << endl;
    else 
        cout << sum + flag << endl;
}
//如果找得到相同的就copy1
//如果在加减的区间里面的话也是copy1
//否则就为最小的绝对值
signed main() {
    int T;cin >> T;
    while(T--)
        solve();
}