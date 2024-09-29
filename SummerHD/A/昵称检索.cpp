#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <unordered_map>


using namespace std;

using ll = long long;

//每月份对应天数的十位数，个位数
unordered_map<int, pair<int,int>> px = {
    {1,{3, 1}},
    {2,{2, 9}},
    {3,{3, 1}},
    {4,{3, 0}},
    {5, {3, 1}},
    {6, {3, 0}},
    {7, {3, 1}},
    {8, {3, 1}},
    {9, {3, 0}},
    {10, {3, 1}},
    {11, {3, 0}},
    {12, {3, 1}}
};

void solve() {
    int n, m;
    cin >> n >> m;
    string v;cin >> v;
    ll ans = 0;
    set<int> N[36]; 

    auto idx = [&](int x) {
        return 26 + x;
    };

    auto check = [&](pair<int,int> x, int loc) {
        auto m = x.first;
        auto d = x.second;
        for(int i = 0; i < m; i ++) {
            auto cc = N[idx(i)].upper_bound(loc);
            if(cc == N[idx(i)].end())
                continue;

            for(int j = 0; j <= 9; j ++) {
                if(i == 0 && j == 0)
                    continue;
                auto ch = N[idx(j)].upper_bound(*cc);
                if(ch != N[idx(j)].end()) {
                    ans++;
                    // cout << v[*cc- 1] << v[*ch - 1] << "\n";
                }
            }
        }
        auto cc = N[idx(m)].upper_bound(loc);
        if(cc == N[idx(m)].end())
            return;
        for(int j = 0; j <= d; j ++) {
            auto ch = N[idx(j)].upper_bound(*cc);
            if(ch != N[idx(j)].end()){
                ans++;
                // cout << v[*cc -1] << v[*ch - 1] << "\n";
            }
        }
        return;
    };

    for(int i = 0; i < v.length(); i ++) {
        if(v[i] >= 'a' && v[i] <= 'z')
            N[v[i] - 'a'].insert(i + 1);
        else 
            N[26 + v[i] - '0'].insert(i + 1);
    }
    while(n --) {
        string t;cin >> t;
        int loc = 0, flag = 0;
        for(auto c: t) {
            auto cv = N[c - 'a'].upper_bound(loc);
            if(cv == N[c- 'a'].end()) {
                flag = 1;
                break;
            }
            loc = *cv;
        }
        if(flag)
            continue;

        auto zf = N[idx(0)].upper_bound(loc); 
        auto of = N[idx(1)].upper_bound(loc);
        if(zf != N[idx(0)].end()) {
            loc = *zf;
            for(int i = 1; i <= 9; i ++) {
                auto cc = N[idx(i)].upper_bound(loc);
                if(cc != N[idx(i)].end()) {
                    // cout << 0 << i << ":\n";
                    check(px[i], *cc);
                }
            }
        }
        if(of != N[idx(1)].end()) {
            loc = *of;
            for(int i = 0; i <= 2; i ++) {
                auto cc = N[idx(i)].upper_bound(loc);
                if(cc != N[idx(i)].end()) {
                    // cout << 10 + i << ":\n";
                    check(px[10 + i], *cc);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    int T;cin >> T;
    while(T--)
        solve();
}