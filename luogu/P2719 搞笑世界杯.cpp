#include <iostream>

using namespace std;

const int N = 1300;
double dp[N][N];

int main() {
    int n; cin >> n;
    n /= 2;
    for(int i = 2; i <= n;i ++) {
        dp[i][0] = dp[0][i] = 1;
    }
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) 
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * 0.5;
    printf("%.4lf", dp[n][n]);
}
