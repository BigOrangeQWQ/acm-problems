#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;
int tr[N], n, m;

int lowbit(int x) {
    return -x & x;
}

void add(int x, int v) {
    for(int i = x; i <= n; i += lowbit(i))
        tr[i] = tr[i] + v;
}

int getSum(int x) {
    int res = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        res = res + tr[i];
    return res;
}

int rangeSum(int l, int r) {
    return getSum(r) - getSum(l - 1);
}

int main(){ 
    cin >> n >> m;
    int last = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        add(i, x - last);
        last = x;
    }

    for(int i = 1; i <= m; i ++) {
        int q; cin >> q;
        if(q == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            add(l, v);
            add(r + 1, -v);
        }
        if(q == 2) {
            int v;
            cin >> v;
            cout << getSum(v) << endl;
        }
    }
}