// #include <iostream>

// using namespace std;

// int gcd(int a, int b) {
//     if(b == 0)
//         return a;
//     else 
//         return gcd(b, a % b);
// }

// int main() {
//     int n, ans, x;
//     cin >> n >> ans;
//     ans = abs(ans);
//     for(int i = 2; i <= n;i ++) {
//         cin >> x;
//         ans = gcd(ans, abs(x));
//     }
//     cout << ans << endl;
// }
#include <iostream>

using namespace std;

#define int long long

int gcd(int a, int b) {
    if(b == 0)
        return a;
    else 
        return gcd(b, a % b);
}
signed main() {
    int n, x;
    int ans, v;
    cin >> n >> x >> ans;
    for(int i = 2; i <= n; i++) {
        cin >> v;
        ans = gcd(ans, v);
    }
    cout << min(x % ans, ans - x  % ans) << endl;
}