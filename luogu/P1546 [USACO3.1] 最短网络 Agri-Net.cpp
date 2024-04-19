#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using PII = pair<int, int>;
struct node {
    int st, ed, w;
};

const int N = 1e5 + 10;

vector<node> E;
vector<int> p(N);

bool cmp(node a, node b) {
    return a.w < b.w;
}

int find(int x) {
    if(p[x] != x) return p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n;i++)
        for(int j = 1; j <= n;j ++)
            cin >> graph[i][j];
    
    for(int i = 1; i <= n;i ++) 
        for(int j = 1; j <= n; j++) 
            if(i != j)
                E.push_back({i, j, graph[i][j]});
    
    for(int i = 1; i <= n; i++)
        p[i] = i;

    sort(E.begin(), E.end(), cmp);
    int res = 0;
    for(auto v: E) {
        if(find(v.st) == find(v.ed)) 
            continue;
        p[find(v.st)] = find(v.ed);
        res += v.w;
    }
    cout << res << endl;
}