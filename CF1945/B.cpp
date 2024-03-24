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

// int gcd(int a, int b) {
//     return !b ? a : gcd(b, a % b);
// }

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    cout << 2 + k / n + k / m << endl;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}