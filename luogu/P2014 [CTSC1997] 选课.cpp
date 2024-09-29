#include <iostream>
#include <vector>

using namespace std;

const int N = 500 + 10;
vector<int> E[N];
vector<vector<int>> dp(N, vector<int>(N));
vector<int> dep(N), v(N);
int n, m;

int dfs(int u, int fa) {
    int dep = 1;
    dp[u][1] = v[u];
    for(auto c: E[u]) {
        int siz = dfs(c, u);
        for(int i = m + 1; i; i--) {
            for(int j = 1; j <= siz && i + j <= m + 1; j++) {
                cout<< u << ' ' << siz << endl; 
                dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[c][j]);
            }
        }
        dep += siz;
    }
    return dep;
}

void dfp(int u, int fa) {
    dep[u] = 1;
    for(auto v: E[u]) {
        dfp(v, u);
        dep[u] += dep[v];
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <=n ;i ++) {
        int k;
        cin >> k >> v[i];
        E[k].push_back(i);
    }
    dfp(0, -1);
    for(int i = 0; i <=n ;i ++)
        cout << i << ' ' << dep[i] << endl;
    dfs(0, -1);
    cout << dp[0][m + 1] << endl;
}