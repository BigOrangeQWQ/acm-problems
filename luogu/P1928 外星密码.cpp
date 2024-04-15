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

string dfs() {
    string res = "";
    char ch;
    int k;
    while(cin >> ch) {
        if(ch == '[') {
            cin >> k;
            string v = dfs();
            for(int i = 1; i <= k; i++)
                res += v;
        }
        else if(ch == ']')
            return res;
        else 
            res += ch;
    }
    return res;
}

void solve() {
    cout << dfs() << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}