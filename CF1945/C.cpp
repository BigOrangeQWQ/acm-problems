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
    int n; cin >> n;
    string s; cin >> s;
    
    vector<int> p(n + 1,0), q(n + 1,0);

    for(int i = 1; i <= n; i++) {
        p[i] = p[i - 1] + !(s[i - 1] - '0'); //0数目
        q[i] = q[i - 1] + (s[i - 1] - '0');  //1数目
    }

    for(int i = n  / 2, j = (n + 1) / 2; i >= 0 || j <= n; i --, j ++) {
        // if(p[i] - p[0] >= (i + 1) / 2 && q[n] - q[i - 1] >= ((n - i) / 2)) {
        //     cout << i << endl;
        //     return;
        // }

        //2 
        //2~1 3 - 2
        // cout << i << ' ' << p[i] - p[0] << ' ' <<  (i + 1) / 2  << ' ' << q[n] - q[i] << (n - j + 1) / 2 << endl;
        // cout << j << ' ' << p[j] - p[0] << ' ' << (j + 1) / 2 << ' ' << q[n] - q[j] << ' ' << (n - j + 1) / 2 << endl;
        if(i >= 0 && p[i] - p[0] >= (i + 1) / 2 && q[n] - q[i] >= (n - i + 1) / 2) {
            cout << i << endl;
            return ;
        }
        //if(j == 4)
        //    cout << 'b' << i << endl;
        if(j <= n && p[j] - p[0] >= ((j + 1) / 2) && q[n] - q[j] >= ((n - j + 1) / 2)) {
            cout << j << endl;
            return ;
        }
    }

    cout << 0 << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}