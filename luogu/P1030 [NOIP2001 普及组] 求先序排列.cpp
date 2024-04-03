#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;

using LL = long long;
vector<PII> tr(100010);
string a, b;


void prevPrint(int u) {
    cout << (char) u;
    if(tr[u].x)
        prevPrint(tr[u].x);
    if(tr[u].y)
        prevPrint(tr[u].y);
}

int dfs(int l1,int r1, int l2, int r2) {
    if(l1 < 0 || r1 < 0 || l2 < 0 || r2 < 0 || l1 > r1 || l2 > r2)
        return 0;
    if(l1 == r1)
        return a[l1];

    int loc;
    for(loc = r1; loc >= l1 && a[loc] != b[r2]; loc--); //根节点在中序所在的位置

    // cout << loc << ' ' << l1<< ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;    
    tr[b[r2]] = {dfs(l1, loc - 1, l2, l2 + (loc - l1) - 1),
                dfs(loc + 1, r1, l2 + (loc - l1), r2 - 1)};
    return b[r2];

}

void solve() {
    cin >> a >> b;
    dfs(0, a.length() - 1, 0, b.length() - 1);
    prevPrint(b[b.length() - 1]);
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}