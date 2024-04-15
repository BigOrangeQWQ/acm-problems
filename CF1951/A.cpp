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

// 10 5 8 9 1 7 
// 0 10 10 10 10 


//对于换第i个来说，第i-1个最大的值小于我，且后面比 j 大的第一个坐标，两个互相减掉
void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int v = p[k];
    int loc = k;
    for(int i = 1; i <= n;i ++) {
        if(v < p[i]) {
            loc = i;
            break;
        }
    }
    int res1 = 0, res2 = 0;

    swap(p[k], p[1]);
    for(int i = 2; i <= n; i ++) {
        if(p[i] < p[1])
            res1++;
        else
            break;
    }
    swap(p[k], p[1]);


    swap(p[k], p[loc]);
    int maxv = 0;
    for(int i = 1; i < loc; i ++) 
        maxv = max(p[i], maxv);
    // cout << loc << ' ' << k << endl;
    if(maxv < p[loc] && loc != 1){
        res2 ++;
        for(int i = loc + 1; i <= n; i++) {
            if(p[i] < p[loc])
                res2++;
            else 
                break;
        }
    }

    // cout << res1 << ' ' << res2 << endl;

    cout << max(res1, res2) << endl;
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}

//7 2 727 10 12 13
//1 2 3   4  5  6 

//1 2 2
//2 7 1
//3 10 4
//4 12 5
//5 13 6
//6 727 3 