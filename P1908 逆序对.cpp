// # 逆序对

// ## 题目描述

// 猫猫 TOM 和小老鼠 JERRY 最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。

// 最近，TOM 老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中 $a_i>a_j$ 且 $i<j$ 的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。注意序列中可能有重复数字。

// **Update:数据已加强。**

// ## 输入格式

// 第一行，一个数 $n$，表示序列中有 $n$个数。

// 第二行 $n$ 个数，表示给定的序列。序列中每个数字不超过 $10^9$。

// ## 输出格式

// 输出序列中逆序对的数目。

// ## 样例 #1

// ### 样例输入 #1

// ```
// 6
// 5 4 2 6 3 1
// ```

// ### 样例输出 #1

// ```
// 11
// ```

// ## 提示

// 对于 $25\%$ 的数据，$n \leq 2500$

// 对于 $50\%$ 的数据，$n \leq 4 \times 10^4$。

// 对于所有数据，$n \leq 5 \times 10^5$

// 请使用较快的输入输出

// 应该不会 $O(n^2)$ 过 50 万吧 by chen_zhe

// ------
#include <iostream>

using namespace std;

const int N = 5e5 + 10;
int num[N], tmp[N];
long long ans;

void merge_sort(int num[], int l, int r) {
    if(l >= r) return ;

    int mid = (l + r) >> 1;
    merge_sort(num, l, mid);
    merge_sort(num, mid + 1 , r);
    
    int k = 0, i = l, j = mid + 1;
    while(i <= mid && j <= r) {
        if(num[i] <= num[j]) tmp[k ++] = num[i ++];
        else tmp[k ++] = num[j ++], ans += mid - i + 1;
    }

    while(i <= mid) tmp[k ++] = num[i ++];
    while(j <= mid) tmp[k ++] = num[j ++];

    // for(int i = 1; i <= n ;)
    for (i = l, j = 0; i <= r; i ++, j ++ ) num[i] = tmp[j];
}

int main() {
    int n; cin >> n;
    for(int i = 1; i <= n;i ++) {
        cin >> num[i];
    }
    merge_sort(num, 1, n);
    cout << ans << endl;
}