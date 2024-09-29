#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

const int logn = 21;
const int maxn = 2e6 + 1;
int dp[maxn + 1][logn + 1];

// int Log[maxn + 1];
// void pre() {
//     // 倍增每次x2,log(r - l + 1)
//     Log[1] = 0, Log[2] = 1;
//     for(int i = 3; i <= maxn;i ++) {
//         Log[i] = Log[i / 2] + 1;
//     }
//     // include <cmath>
//     // floor(log2(r - l + 1))
// }

int main() {
    int n = read(), k = read();

    // pre();
    for(int i = 1; i <= n;i ++) {
        dp[i][0] = read();
    }

    // (1 << j) == 2^j

    // nlogn预处理，O1查询
    for(int j = 1; j <= logn; j ++) {
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    for(int i = 1; i <= k; i ++) {
        int l = read(), r = read();
        // int lt = Log[r - l + 1];
        int lt = floor(log2(r - l + 1));
        int ans = max(
            dp[l][lt],
            dp[r - (1 << lt) + 1][lt]
        );
        // cout << ans << endl;
        printf("%d\n", ans);
    }
}