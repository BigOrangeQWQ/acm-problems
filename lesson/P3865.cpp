#include <iostream>

using namespace std;


const int maxn = 2000001;
const int logn = 21;
int dp[maxn + 1][logn + 1];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int lg[maxn];
void Log() {
    lg[1] = 0, lg[2] = 1;
    for(int i = 3; i <= maxn; i++) 
        lg[i] = lg[i >> 1] + 1;
}

void solve() {
    int n = read(), k = read();

    for(int i = 1; i <= n;i ++) {
        dp[i][0] = read();
    }

    Log();
    // dp i,j 代表第 i 个数后第 2^j - 1 个数的最大值
    for(int j = 1; j <= logn; j ++) {
        //j + (1 << i) - 1 为右端点
        for(int i = 1; i + (1 << j) - 1 <= n; i ++) {
            //那 dp[i][j] 为 [i, i + 2^j - 1]
            //可以转为 [i, i + 2^(j-1) - 1] ~ [i + 2^(j-1) - 1, i + 2^j - 1]
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    //它们之间的差值为 r - l + 1， 其中化为 log2 可得 v
    //dp[l][v] ~ dp[r - (1 << v) - 1][v]
    //x + 2^v - 1 = r
    for(int i = 1; i <= k; i ++) {
        int l = read(), r=read();
        int v = lg[r - l + 1];
        printf("%d\n", max(dp[l][v],dp[r - (1 << v) + 1][v]));
    }

}

signed main() {
    // int T;cin >> T;

    int T = 1;
    while(T --> 0) {
        solve();
    }
}