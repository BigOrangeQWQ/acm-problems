#include <iostream>
<<<<<<< HEAD
=======
#include <iostream>
>>>>>>> 4ee86fac2d53568a3b33a5198afd6ad5f9d88c97
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
<<<<<<< HEAD

=======
#include <map>
>>>>>>> 4ee86fac2d53568a3b33a5198afd6ad5f9d88c97

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;

void solve() {
<<<<<<< HEAD
    
=======
    int n; cin >> n;
    vector<string> g(n), w(n);
    for(int i = 0; i < n;i ++) {
        cin >> g[i] >> w[i];
    }

    //预处理，对于i,j来说它是否相等
    vector<vector<int>> e(n, vector<int> (n));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            e[i][j] = (g[i] == g[j] || w[i] == w[j]);
    
    vector<vector<int>> dp(1 << n, vector<int>(n));
    for(int x = 0; x < n; x++){
        dp[1 << x][x] = 1; //给二进制第 x 位置为 1，且代表其选中第 x 个
        // cout << (1 << x) << ' ' << x << endl;
    }
    // cout << "----" << endl;

    int ans = 0;
    for(int s = 1; s < (1 << n); s++) {
        for(int x = 0; x < n; x++) {
            if(!dp[s][x]) //如果没标记， continue
                continue;
            // 答案是第一维所表示的1的最大数目
            ans = max(ans, __builtin_popcount(s));
            for(int y = 0; y < n; y++) { // 对于每个y来说
                //如果当前位没选，且xy可以靠近（即有任一相同）
                if(((~s >> y) & 1) && e[x][y])
                    dp[s | (1 << y)][y] = 1; //更新dp[使第 i 位置为1][第 y 选中]
            }
        }
    }

    cout << n - ans << endl;
>>>>>>> 4ee86fac2d53568a3b33a5198afd6ad5f9d88c97
}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}