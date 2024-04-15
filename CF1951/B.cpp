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
// #define int long long

using PII = pair<int, int>;
using LL = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int v = 0, lx = false;//有没有两个1连起来的情况，v是1的总数
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '1')
            v++;
        if(s[i] ==  s[i + 1] && s[i] == '1')
            lx = true;
    }

    if(v % 2 == 1 || (lx == true && v < 4))
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;

    // for(auto c: s) 
        // if(c == '1')
            // v++;
    
    // if(v % 2 == 1 || (s.length() <= 2 && v == s.length()))
    //     cout << "NO" << endl; 
    // else
    //     cout << "YES" << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}