#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

void solve() {
    int h, m;
    scanf("%d:%d", &h, &m);
    if(h < 12) {
        if(h == 0)
            printf("%02d:%02d AM\n", h + 12, m);
        else 
            printf("%02d:%02d AM\n", h, m);
        // cout << h << ":" << m << " AM" << endl;
    }
    else {
        if(h == 12)
            printf("%02d:%02d PM\n", h, m);

        else 
            printf("%02d:%02d PM\n", h - 12, m);
        // cout << h - 12 << ":" << m << " PM" << endl;
    }
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}
