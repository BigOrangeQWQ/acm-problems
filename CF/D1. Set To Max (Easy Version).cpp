#include <bits/stdc++.h>

using namespace std;

#define endl '\n'


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) 
        cin >> b[i];
    
    vector<int> l(n), r(n);
    vector<int> stk;
    for(int i = 0 ; i < n;i ++) {
        while(!stk.empty() && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }
        l[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
    }
    stk = vector<int>();
    for(int i = n - 1; i >= 0; i --) {
        while(!stk.empty() && a[stk.back()] <= a[i]) {
            stk.pop_back();
        }
        r[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        // l[i] 第i个元素之前第一个大于a[i]的下标
        // r[i] 第i个元素之后第一个大于a[i]的下标
        // b[j] == a[i] 找到可以赋值的最大值，且l,r区间可以赋值到j
        // 即可以赋值的元素a[i] 的上一个比它大的值的下标l[i]
        // 和右边比它大的值的下标r[i]覆盖了 j，则j++
        // cout << i <<  ' '<< j << ' ' << l[i] << ' ' << r[i] << endl;
        while (j < n && b[j] == a[i] && j > l[i] && j < r[i]) {
            j++;
        }
    }
    if (j == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() { 
    int T; cin >> T;
    while(T--) {
        solve();
    }
}

