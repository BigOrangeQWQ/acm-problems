#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

int check(string a, string b) {
    int df = 0;
    for(int i = 0; i < a.length(); i ++) {
        if(a[i] != b[i])
            df ++;
    }
    return df;
}

void solve() {
    int n; string s;
    cin >> n >> s;
    for(int i = 1; i <= n / 2; i++) {
        if(n % i) 
            continue;
        int bad = 0;
        for(int j = 0; j < i ;j ++) {
            map<int, int> mp;
            for(int k = j; k < n; k += i) {
                mp[s[k] - 'a'] ++;
            }
            int maxx = 0;
            for(auto x: mp) 
                maxx = max(x.second, maxx);
            
            bad += n / i - maxx;
        }

        if(bad <= 1) {
            cout << i << endl;
            return;
        }
    }

    cout << n << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}