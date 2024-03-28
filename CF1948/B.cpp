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
    int n;cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n ;i ++) 
        cin >> p[i];

    // pi / 10 十位数
    // pi % 10 个位数
    // pi
    int last = p[n]; //最大的数
    
    for(int i = n - 1; i >= 1; i--) {
        if(p[i] > last) {
            if(p[i] % 10 <= last && p[i] / 10 <= p[i] % 10) {
                last = p[i] / 10;
                continue;
            }
            cout << "NO" << endl;
            return;
        }
        last = p[i];
    }
    cout << "YES" << endl;
    return ;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}