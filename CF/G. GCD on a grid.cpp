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

int dp[150][150];

int gcd(int a, int b) {
    if(b == 0) 
        return a;
    return gcd(b, a % b);
}
void solve() {
    
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}