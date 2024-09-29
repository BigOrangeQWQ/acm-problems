#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <deque>
#include <numeric>

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;

using LL = long long;

// 20 6
// 6 12
// 12 3
// 48 36
// 也就是说，如果一个序列的GCD本身为升序，我只需要删除头尾，其结果仍然是升序
//  给定序列a
// 
// 10 50 2 10 20
// ---
// 10 50 - 10
// 50 2 - 2
// 2 10 - 2
// 10 20 - 10
// b- 10 2 2 10
// 


// 给定 数组 a，数组 bi 由 gcd(a_i, a_i+1) 求出。
// 可删除一次 a 数组中任一元素，问 b 数组最后是否为升序
// [!]对于b数组来说，b[i]非升序，则其由a数组的gcd(i-1,i) gcd(i,i+1)求得，删除这元素影响其b数组结果，所以
// 当 b[i] < b[i - 1] 删除 a 中 i-1, i, i+1 任一得新数组，求出b数组若为升序即正确，否则单次删除无法得到升序数组

// 假设：若存在 b[i] < b[i - 1] 可删除 i-1,i, i+1之外的元素求得新 b 数组为升序。
// 因数组b[i] 只受到a数组 gcd(i-1,i) gcd(i,i+1) 两个数对求得，可试删除 i-1,i,i+1 之外的任一元素，但其无法影响到b[i]的最终结果


void solve() {
    int n;
    cin >> n;
    vector<int> q(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> q[i];
    }
    bool flag = true;
    int loc;
    for(int i = 0; i < n - 1;i ++) {
        b[i] = gcd(q[i], q[i + 1]);
        if(i >= 1 && b[i] < b[i - 1]) {
            flag = false;
            loc = i;
        }
    }
    if(flag) {
        cout << "YES" << endl;
        return;
    }

    vector<int> a[3];

    for(int i = 0; i < n; i++) {
        if(i != loc - 1)
            a[0].push_back(q[i]);
    }
    for(int i = 0; i < n; i++) {
        if(i != loc + 1)
            a[1].push_back(q[i]);
    }
    for(int i = 0; i < n; i++) {
        if(i != loc)
            a[2].push_back(q[i]);
    }

    bool ans = true;
    for(int i = 0, lst, now; i < n - 2;i ++) {
        now = gcd(a[0][i], a[0][i + 1]);

        if(i >= 1 && now < lst) {
            ans = false;
            break;
        }
        lst = now;
    }
    if(ans) {
        cout << "YES" << endl;
        return;
    }
    ans = true;
    for(int i = 0, lst, now; i < n - 2;i ++) {

        now = gcd(a[1][i], a[1][i + 1]);

        if(i >= 1 && now < lst) {
            ans = false;
            break;
        }
        lst = now;
    }
    if(ans) {
        cout << "YES" << endl;
        return;
    }
    ans = true;
    for(int i = 0, lst, now; i < n - 2;i ++) {
        now = gcd(a[2][i], a[2][i + 1]);

        if(i >= 1 && now < lst) {
            ans = false;
            break;
        }
        lst = now;
    }
    if(ans) {
        cout << "YES" << endl;
        return;
    }
    else {
        cout << "NO" << endl;
    }

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}