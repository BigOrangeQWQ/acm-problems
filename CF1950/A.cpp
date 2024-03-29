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
char qp[50][50];

void solve() {

    int a, b, c;
    cin >> a >> b >> c;
    if(a < b && b < c)
        cout << "STAIR" << endl;
    else if( a < b && b > c)
        cout <<"PEAK" << endl;
    else 
        cout << "NONE" << endl;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}