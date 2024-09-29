#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, floc;cin >> n;
    vector<int> p(n + 1), res(n + 1);
    set<int> tag;

    for(int i = 1; i <= n;i ++) {
        cin >> p[i];
        tag.insert(i);
        if(p[i] == 1) 
            floc = i;
    }

    if(floc % 3 == 0 || floc == 1) {
        for(int i = 2; i <= (n - 1); i += 2) {
            // cout << i << endl;
            res[i] = n - p[i] + 2;
            tag.erase(n - p[i] + 2);
        }
        for(int i = 1; i <= n; i ++) {
            if(res[i] == 0 && p[i] != 1) {
                // cout << i << endl;
                auto it = tag.upper_bound(n - p[i] + 1);
                // cout << i << ' ' << *it << endl;
                if(it != tag.begin()) {
                    it--;
                    res[i] = *it;
                } 
                tag.erase(it);
                // res[i] = n - p[i] + 1;

                // tag[n - p[i] + 2] = 1;
            }
        }
    }
    for(auto i: tag) {
        res[floc] = i;
        break;
    }
    for(int i = 1; i <=n ;i ++) {
        cout << res[i] << " \n"[i == n];
    }
}

int main() {
    int T;cin >> T;
    while(T--) 
        solve();
}

// 1 2 3 4
//   4 
//

// // 
// 4 3 1 2 5 6
// 3 5 4 6 2 1




// 4 1 3 2 5
//   5 \

// 6 5 4 3 2 1 
// 1 2 3 4 5 6

