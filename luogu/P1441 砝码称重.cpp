#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<bool> dp(N), vis(N);
vector<int> p(N);
int n, m, res, cnt;

void solve() {
    fill(dp.begin(),dp.end(), 0);
    dp[0] = true;
    int ooo = 0;
    
    for(int i = 1; i <= n; i++) {
        if(vis[i])
            continue;
        // cout << p[i] << endl;

        for(int j = 2000; j >= 0; j --) {
            // if(dp[j])
            //     cout << dp[i] << ' ' << dp[i + p[i]] << ' ' << p[i] << endl;
            if(dp[j] && !dp[j + p[i]]) {
                dp[j + p[i]] = true;
                ooo ++;
            }
        }
    }
    res = max(ooo, res);
}

void dfs(int num) {
    if(num == m) {
        solve();
        return;
    }
    for(int i = cnt + 1; i <= n;i++) {
        if(!vis[i]){
            vis[i] = 1;
            cnt = i;
            dfs(num + 1);
            vis[i] = 0;
        }
    }
}

int main() {

    cin >> n >> m;
    for(int i = 1; i <= n;i ++) 
        cin >> p[i];
    
    dfs(0);
    cout << res << endl;
}