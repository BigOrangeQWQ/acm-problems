#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
    int n, c, d;
    cin >> n >> c >> d;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    vector<vector<int>> p(n + 1, vector<int> (n + 1));
    map<int, int> t1; int maxv = 1e18;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n ;j ++)  {
            int x; cin >> x;
            t1[x]++;
            maxv = min(x, maxv);
    }

    int flag = true;

    map<int, int> t2;
    p[1][1] = maxv;
    for(int i = 1; i <= n; i++) {
        for(int j = 1;j <= n; j++) {
            if(i + 1 <= n)
                p[i + 1][j] = p[i][j] + c;
            if(j + 1 <= n)
                p[i][j + 1] = p[i][j] + d;
        }
    }

    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n;j ++) 
            t2[p[i][j]] ++;
        
    // cout << endl;
    // for(int i = 1; i <= n; i++) 
    //     for(int j = 1; j <= n ;j ++) 
    //         cout <<  p[i][j] << " \n"[j == n];
        

    for(auto i: t1) {
        if(t2.find(i.first)->second != i.second){
            flag = false;
            break;
        }
    }
    

    if(flag)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}