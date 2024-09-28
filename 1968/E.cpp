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

void solve() {
    int n;
    cin >> n;
    if(n == 2) {
        cout << "1 1\n1 2\n"; 
    }
    else if(n == 3) {
        cout << "2 1\n2 3\n3 1\n";
    }
    else {
        cout << "1 1\n2 1\n";
        for(int i = 3; i < n; i++){
            cout << 1 << ' ' << i << endl;
        } 
        cout << n << ' ' << n <<endl;
    }
    cout << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}