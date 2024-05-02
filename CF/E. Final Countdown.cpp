#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

#define endl '\n'

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // 删除前导 0
    reverse(s.begin(), s.end());
    while(s.back() == '0') {
        s.pop_back(); 
        n --;
    }

    vector<int> f(n);
    for(int i = 0;i < n; i++) {
        f[i] = s[i] - '0';
    }

    //这种前缀和达到了
    //1234
    //+123
    // +12
    //  +1
    //的神奇效果，OMG
    //1 3 6 10
    //1 3 7 0
    for(int i = n - 2; i >= 0; i--) {
        f[i] += f[i + 1];
    }

    for(int i = 0; i < n; i++) {
        if(f[i] >= 10) {
            if(i == n - 1) {
                n++;
                f.push_back(0);
            }
            f[i + 1] += f[i] / 10;
            f[i] %= 10;
        }
    }

    reverse(f.begin(), f.end());
    for(auto i: f) 
        cout << i;
    cout << "\n";
}

signed main() {
    // int n; cin >> n;
    int T; cin >> T;
    while(T --> 0) {
        solve();
    }
}

