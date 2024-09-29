#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<vector<char>> p(600, vector<char>(600));
    

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n;i ++) {
        for(int j = 1; j <= m; j++){
            cin >> p[i][j];
        }
    }

    bool flag = false;
    if(p[1][1] == p[n][m])
        flag = true;
    if(p[1][m] == p[n][1])
        flag = true;

    for(int i = 1; i <= m && !flag; i++) {
        if(p[n][m] != p[n][1])
            break;
        if(p[1][i] == p[n][m]){
            flag = true;
        }
    }

    for(int i = 1; i <= n && !flag; i++) {
        if(p[1][m] != p[n][m])
            break;
        if(p[i][1] == p[1][m]){ 
            flag = true;
        }
    }


    for(int i = 1; i <= m && !flag; i++) {
        if(p[1][1] != p[1][m])
            break;
        if(p[n][i] == p[1][1]){
            flag = true;
        }
    }

    for(int i = 1; i <= n && !flag; i++) {
        if(p[1][1] != p[n][1])
            break;
        if(p[i][m] == p[1][1]){
            flag = true;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int T;cin >> T;
    while(T--){
        solve();
    }
}