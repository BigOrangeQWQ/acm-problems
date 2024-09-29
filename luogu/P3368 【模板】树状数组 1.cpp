#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int tr[N];
int n, m;

int lowbit(int x) {
    return -x & x;
}

void add(int x, int v) {
    for(int i = x; i <= n; i += lowbit(i))
        tr[i] = tr[i] + v; 
}

int getSum(int x) {
    int res = 0;
    for(int i = x ;i > 0; i -= lowbit(i))
        res = res + tr[i];
    return res;
} 

int rangeSum(int l, int r) {
    return getSum(r) - getSum(l - 1);
}

int main() {
    // int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n;i ++) {
        int x; cin >> x;
        add(i, x);
    }
    for(int i = 1; i <= m;i ++) {
        int x, l, r;
        cin >> x >> l >> r;
        if(x == 1) {
            add(l, r);
        }
        if(x == 2) {
            cout << rangeSum(l, r) << endl;
        }
    }
}