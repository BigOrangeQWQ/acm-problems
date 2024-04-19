#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

using LL = long long int;

using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    for(int k = n; k >= 1; k --) {
        vector<int> t(n), pre(n + 2);
        for(int i = 0; i < n;i ++) {
            t[i] = s[i] - '0';
        }
        int cnt = 0;// 前缀和[总操作次数]
        for(int i = 0; i < n;i ++) {
            cnt -= pre[i]; //pre为差分数组，这里减少到此的操作次数
            t[i] ^= (cnt & 1); //奇数次操作有效，然后与原数组进行操作
            if(t[i] == 0) { //操作后为0，则需要增加1操作次数，进行前缀和差分的赋值
                if(i + k <= n) {
                    cnt ++;
                    pre[i + k] ++;
                    t[i] = 1;
                }
                else {
                    break; //无法操作，则break
                }
            }
        }
        int res = 2000;
        for(auto i: t) {
            res = min(i, res);
        }
        if(res == 1) {
            cout << k << endl;
            return;
        }
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
