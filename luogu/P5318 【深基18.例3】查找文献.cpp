#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N =  1e5 + 10;
vector<int> E[N];
vector<bool> dis(N);

void dfs(int u, int fa) {
    if(!dis[u]){
        dis[u] = true;
        cout << u << ' ';
    }
    else 
        return;

    for(auto v: E[u])
        if(v != fa)
            dfs(v, u);
}

void bfs(int u) {
    queue<int> q;
    q.push(u);
    
    while(q.size()) {

        int u = q.front();q.pop();
        if(dis[u])
            continue;

        cout << u << ' ';
        dis[u] = true;
        for(auto v: E[u]) 
            q.push(v);

    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m;i ++) {
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
    }
    for(int i = 0; i <= n; i++)
        sort(E[i].begin(), E[i].end());
    dfs(1, 0);
    cout << endl;
    fill(dis.begin(), dis.end(), false);
    bfs(1);
    // bfs();
}