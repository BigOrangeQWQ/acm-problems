#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int N = 100;
struct {
    int l, r, v;
} tree[N];
int last[N], mid[N];

vector<int> ans;

void preTrav(int root) {
    printf("%d ",root);
    if(tree[root].l) preTrav(tree[root].l);
    if(tree[root].r) preTrav(tree[root].r);
}

void queueTrav(int root) {
    queue<int> q;
    q.push(root);
    while(q.size()) {
        int v = q.front();q.pop();
        ans.push_back(v);
        // cout << v << ' ';
        if(tree[v].l) q.push(tree[v].l);
        if(tree[v].r) q.push(tree[v].r);
    }
}

int build_tree(int ll, int lr, int ml, int mr) {
    int root = last[lr]; // 根节点
    int loc;
    for(loc = ml; mid[loc] != root && loc <= mr; loc++);
    // cout << ll << ' ' << loc - ml + ll << ' ' << ml << ' ' << loc - 1 << endl;
    if(loc > ml) tree[root].l = build_tree(ll, loc - ml + ll - 1, ml, loc - 1);
    if(loc < mr) tree[root].r = build_tree(loc - ml + ll, lr - 1 , loc + 1, mr);
    return root;
}


int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> last[i];
    for(int i = 1; i <= n; i++) 
        cin >> mid[i];
    build_tree(1, n, 1, n);

    // preTrav(last[n]);
    // cout << endl;
    queueTrav(last[n]);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}