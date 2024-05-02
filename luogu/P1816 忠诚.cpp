#include <iostream>

using namespace std;
using LL = long long;

const int N = 1e5 + 10;

int value[N];
int INF = 1 << 30;
struct XTree {
    int l, r;
    LL sum;
} tree[N * 4];

auto push_up = [](int p) {
    tree[p].sum = min(tree[p << 1].sum , tree[p << 1 | 1].sum);
};

auto gmid = [](int l, int r) {
    return l + ((r - l) >> 1);
};

void build(int l, int r, int p) {

    tree[p] = {l, r, INF};
    if(l == r) {
        tree[p].sum = value[l];
        return;
    }
    int mid = gmid(l, r);
    build(l, mid, p << 1), build(mid + 1, r, p << 1 | 1);
    push_up(p);
} 

void modify(int x, int u, int v) {
    if(tree[x].l == tree[x].r && tree[x].l == u) {
        tree[x].sum = v;
        return;
    }
    int mid = gmid(tree[x].l, tree[x].r);

    if(u <= mid) 
        modify(x << 1, u, v);
    else 
        modify(x << 1 | 1, u, v);
    push_up(x);
}

LL query(int l, int r, int p) {
    if(tree[p].l >= l && tree[p].r <= r)
        return tree[p].sum;
    
    int mid = gmid(tree[p].l, tree[p].r);
    LL sum = INF;
    if(l <= mid)
        sum = min(sum, query(l, r, p << 1));
    if(r > mid)
        sum = min(sum, query(l, r, p << 1 | 1));
    return sum;
}

int main() {
    LL n, m, p, q;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> value[i];
    build(1, n, 1);

    while(m--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r, 1) << " ";
    }

}