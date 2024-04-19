#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, cnt;

struct node {
    int st, ed, w;
};
vector<node> e;

int find(int x, vector<int> &p) {
    // cout << x << ' ' << p[x] << endl;
    if(p[x] != x)
        return p[x] = find(p[x], p);
    return p[x];
}

bool solve(int v) {
    int maxv = -1, num = 0;
    cnt = 0;

    vector<int> p(n + 1);

    for(int i = 1; i <= n;i ++) 
        p[i] = i;

    for(auto v: e) {
        if(find(v.st, p) == find(v.ed, p))
            continue;
        p[find(v.st, p)] = find(v.ed, p);
        maxv = max(maxv, v.w);
        cnt++;
    }

    for(int i = 1; i <= n;i ++)
        if(p[i] == i)
            num ++;
    if(num != 1)
        return false; 
    return maxv >= v;
}

int main() {
    int l = 0, r = -1;
    cin >> n >> m;
    for(int i = 1; i <= m;i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        e.push_back({x, y, z});
        e.push_back({y, x, z});
        r = max(z, r);
    }

    auto cmp = [](node a, node b) {
        return a.w < b.w;
    };
    sort(e.begin(), e.end(), cmp);
    r += 100;
    while(l + 1 < r) {
        // cout << l << ' ' << r << endl;
        int mid = (l + r) >> 1;
        if(solve(mid)) l = mid;
        else r = mid;
    }
    cout << cnt << ' ' <<  l << endl;
}