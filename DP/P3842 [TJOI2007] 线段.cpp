// # [TJOI2007] 线段

// ## 题目描述

// 在一个 $n \times n$ 的平面上，在每一行中有一条线段，第 $i$ 行的线段的左端点是$(i, L_{i})$，右端点是$(i, R_{i})$。

// 你从 $(1,1)$ 点出发，要求沿途走过所有的线段，最终到达 $(n,n)$ 点，且所走的路程长度要尽量短。

// 更具体一些说，你在任何时候只能选择向下走一步（行数增加 $1$）、向左走一步（列数减少 $1$）或是向右走一步（列数增加 $1$）。当然，由于你不能向上行走，因此在从任何一行向下走到另一行的时候，你必须保证已经走完本行的那条线段。

// ## 输入格式

// 第一行有一个整数 $n$。

// 以下 $n$ 行，在第 $i$ 行（总第 $(i+1)$ 行）的两个整数表示 $L_i$ 和 $R_i$。

// ## 输出格式

// 仅包含一个整数，你选择的最短路程的长度。

// ## 样例 #1

// ### 样例输入 #1

// ```
// 6
// 2 6
// 3 4
// 1 3
// 1 2
// 3 6
// 4 5
// ```

// ### 样例输出 #1

// ```
// 24
// ```

// ## 提示

// 我们选择的路线是

// ```
//  (1, 1) (1, 6)
//  (2, 6) (2, 3)
//  (3, 3) (3, 1)
//  (4, 1) (4, 2)
//  (5, 2) (5, 6)
//  (6, 6) (6, 4) (6, 6)
// ```
// 不难计算得到，路程的总长度是 $24$。 

// 对于 $100\%$ 的数据中，$n \le 2 \times 10^4$，$1 \le L_i \le R_i \le n$。

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long


void solve() {
    int n;cin >> n;
    vector<pair<int,int>> p(n + 10), dp(n + 10);
    for(int i = 1; i <= n ; i++) {
        cin >> p[i].first >> p[i].second;
    }
    auto dis = [](int a, int b) {return abs(a - b);};

    dp[1].first =dis(1, p[1].second) + dis(p[1].second, p[1].first); // 当前行走完且到达左端点的最短距离
    dp[1].second =  dis(1, p[1].second);  // 当前行走完且到达右端点的最短距离
    for(int i = 2; i <= n; i++) {
        //转移只可能从端点开始
        dp[i].first = min(dp[i - 1].first + dis(p[i - 1].first, p[i].second) + dis(p[i].first, p[i].second),
                            dp[i - 1].second + dis(p[i - 1].second, p[i].second) + dis(p[i].first, p[i].second)) + 1;

        dp[i].second = min(dp[i - 1].first + dis(p[i - 1].first, p[i].first) + dis(p[i].first, p[i].second), 
                            dp[i - 1].second + dis(p[i - 1].second, p[i].first) + dis(p[i].first, p[i].second)) + 1;
    }
    cout << 
        min(
            dp[n].first + dis(p[n].first, n),dp[n].second + dis(p[n].second, n)
        )
    << endl;
}

signed main() {
    int T = 1;
    while(T --> 0) {
        solve();
    }
}


//DP 三要素
//设状态，dp[i][1] 为 走完这一段后右端点所需