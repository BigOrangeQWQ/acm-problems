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

using PII = pair<int, int>;
using LL = long long;

// sta表示状态， sti表示国王数， dp状态数组
int sta[2000], sti[2000], dp[10][2000][100];
int n, k, cnt;

//cur 当前位于的位数
//num 当前国王数
void dfs(int x, int cur, int num) {
    if(cur >= n) {
        cnt ++;
        sta[cnt] = x;
        sti[cnt] = num;
        return;
    }
    dfs(x, cur + 1, num); //当前位置不
    dfs(x + (1 << cur), cur + 2, num + 1); //当前位置放
}

bool check(int x, int y) {
    x = sta[x], y = sta[y];
    if(x & y) return false;
    if((x >> 1) & y) return false;
    if((x << 1) & y) return false;

    return true;
}

void solve() {
    cin >> n >> k;
    dfs(0, 0, 0);
    // for(int i = 1;i <= n;i ++)
    for(int i = 1;i <= cnt;i ++) {
        //第i行第j个状态，用了k个皇帝
        //dp i,j,k
        dp[1][i][sti[i]] = 1;
    }

    for(int i = 2; i<= n;i ++) {
        for(int j = 1; j <= cnt; j ++) {
            for(int z = 1; z <= cnt; z ++) {
                if(check(j, z)) {
                    for(int p = sti[j]; p <= k; p++)
                        dp[i][j][p] += dp[i - 1][z][p - sti[j]];
                }
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= cnt; i++) {
        res += dp[n][i][k];
    }
    cout << res << endl;
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}