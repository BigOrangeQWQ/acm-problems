#include <iostream>
#include <vector>

using namespace std;



void solve() {
    int n, k;
    cin >> n >> k;
    string a, b, x;
    cin >> x;
    a = " " + x;
    cin >> x;
    b = " " + x;

    // 前缀和查询每个字母的数量
    vector<vector<int>> cnt1(30, vector<int>(n + 2, 0)), 
                        cnt2(30, vector<int>(n + 2, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= 25; j++) {
            cnt1[j][i] += cnt1[j][i - 1] + (a[i] - 'a' == j);
            cnt2[j][i] += cnt2[j][i - 1] + (b[i] - 'a' == j);
        }
    }

    while(k --) {
        int l, r;
        cin >> l >> r; 
        int ans = 0;
        for(int i = 'a'; i <= 'z';i ++) {
            int c = i - 'a';
            // cout << cnt1[c][r] << ' ' << cnt1[c][l - 1] << ' ' << cnt2[c][r] << ' ' << cnt2[c][l -1 ] << endl; 
            ans += abs((cnt1[c][r] - cnt1[c][l - 1]) - (cnt2[c][r] - cnt2[c][l - 1]));
            // cout << (char)i << ":" << ans << endl;
        }
        cout << ans / 2 << '\n';
    }
}


int main() {
    int T;cin >> T;
    while(T--)
        solve();
}
