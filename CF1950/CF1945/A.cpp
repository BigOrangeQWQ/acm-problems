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

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(b % 3 != 0 && b % 3 + c >= 3) {
        c -= (3 - b % 3);
        b += (3 - b % 3);
        cout << a + b / 3 +  ((c + 2)/ 3) << endl;
    }
    else if(b % 3 == 0) {
        cout << a + b / 3 + ((c + 2)/ 3)  << endl;
    }
    else
        cout << -1 << endl;
    // if(b % 3 <= c)
    //     cout << a + (b / 3) + c - (b % 3) << endl;
    // else 
    //     cout << -1 << endl;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}