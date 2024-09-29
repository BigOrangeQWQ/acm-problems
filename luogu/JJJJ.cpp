#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int N = 1010;
int dp[N][N];
int dp2[N][N];
int cst[N][N], v[N][N];

signed main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <=n ;i ++) 
        for(int j = 1; j <= m; j++) 
            cin >> v[i][j];
    
    for(int i = 1; i <=n ;i ++) 
        for(int j = 1; j <= m; j++) 
            cin >> cst[i][j];
    
    dp[1][1] = v[1][1];
    for(int i = 1; i <=n ;i ++) {
        for(int j = 1; j <= m;j ++) {
            dp[i][j] = max(dp[i - 1][j] - cst[i][j], dp[i][j - 1] - cst[i][j]);
        }
    }
    
}