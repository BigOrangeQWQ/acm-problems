#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> p(n);
    vector<int> vis(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] --;
        if(i == p[i])
            vis[i] = true;
    } 
    int res = 0, ans = 0;
    for(int i = 0 ; i < n; i ++) {
        if(!vis[i]) {
            int x = i, cnt = 0;
            while(!vis[x]) { //如果元素遥相呼应，则 cnt 终止于 2
                // 每次交换成功，可以得 1 操作次数，直至交换到已回去的点
                // cout << p[x] << ' ';
                cnt ++ ;
                vis[x] = true;
                x = p[x];
            }
            // cout << "x" << cnt << endl;
            res += (cnt % 3 == 2);
            ans += cnt / 3;
        }
    }

    cout << ans + (res + 1) / 2 << endl;

}


signed main() {
    int T;cin >> T;
    while(T--) {
        solve();
    }
}