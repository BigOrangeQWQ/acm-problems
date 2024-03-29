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
// void solve() {
//     int a, b, c, res = 0;
//     cin >> a >> b >> c;
//     if(a + 1 != c) {
//         cout << "-1" << endl;
//         return;
//     }
//     queue<int> q;
//     q.push(0);
//     while(!q.empty()) {
//         int x = q.front();q.pop();

//         if(a) {
//             a--;
//             q.push(x + 1);
//             q.push(x + 1);
//         }
//         else if(b) {
//             b--;
//             q.push(x + 1);
//         }

//         res = x;
//     }
//     cout << res << endl;
// }

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    //a + b + c == b 
    if(a + 1 != c) {
        cout << "-1" << endl;
        return;
    }
    int n = 1, res = 0;
    while(n - 1 < a) 
        n <<= 1, res ++;
    cout << n << ' ';
    int t = n - c;
    cout << t << ' ' << res << ' ';

    if(b > t)
        res += (b - t + c - 1) / c;
        //(3 - 2 + 6 - 1)/ 6

    cout << res << endl;
    //5 3 6
    //0, 1, 3, 7,
    //
    //cnt = 4
    //n = 8
    //t = n - 6 = 2
    //a
    //aa
    //aabb
    //cccccc
}


signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}