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
#define int long long

using PII = pair<int, int>;

using LL = long long;

int to_int(string x) {
    int ans = 0;
    int cnt = 1;
    for(auto c: x) {
        ans += cnt * (c - '0');
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= 10000; i ++) {
        int cnt = i*n; 
        // '222222' 求(a-b) 位 n = n * a- b
    } 
} 

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}