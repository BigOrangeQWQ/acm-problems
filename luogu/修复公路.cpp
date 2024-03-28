#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second

int find(vector<int> &fa, int a) {
    // cout << fa[a] << ' '  << a << endl;
    // for(auto i: fa) {
    //     cout << fa[i] << ' ';
    // }
    if(fa[a] != a) return fa[a] = find(fa, fa[a]);
    return fa[a];
}

int check(vector<int> &p, int n) {
    int res = 0;
    for(int i = 1; i <= n; i ++) 
        if(p[i] == i) {
            res ++;
            // cout << p[i] << ' ' << i << endl;
        }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> fa(n + 1);
    for(int i = 1; i <= n; i++)
        fa[i] = i;

    // for(auto i: fa) {
    //     cout << fa[i] << ' ';
    // }

    vector<pair<int,pair<int,int>>> p(m + 1);
    for(int i = 1; i <= m; i++) 
        cin >> p[i].y.x >> p[i].y.y >> p[i].x;
    
    sort(p.begin() + 1, p.end());

    for(int i = 1; i <= m;i++) {
        // cout << p[i].x << ' ' <<  p[i].y.x << ' ' << p[i].y.y << endl;

        fa[find(fa, p[i].y.x)] = find(fa, p[i].y.y);
        // for(auto i: fa) {
        // cout << fa[i] << ' ';
        // }
        // cout << endl;

        if(check(fa, n) == 1) {
            cout << p[i].x << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    // int T;cin >> T;
    int T = 1;
    while(T-->0) 
        solve();
}