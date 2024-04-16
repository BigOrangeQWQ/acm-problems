#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;

vector<int> E[N], scc[N];
vector<int> stk, vis(N), low(N), dfn(N),in_stk(N);
int cnt, dfn_cnt;

vector<int> col(N), o_vis(N);

void tarjan(int u) {
    low[u] = dfn[u] = ++dfn_cnt;
    stk.push_back(u), in_stk[u] = true;

    for(auto v: E[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(dfn[u] == low[u]) {
        ++cnt;
        int v = 0;
        while(u != v) {
            v = stk.back(); stk.pop_back();
            col[v] = cnt;
            in_stk[v] = false;
            scc[cnt].push_back(v);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        E[x].push_back(y);
    }
    // tarjan
    for(int i = 1; i<= n;i ++) {
        if(!dfn[i])
            tarjan(i);
    }

    cout << cnt << endl;
    for(int i = 1; i <=cnt; i++)
        sort(scc[i].begin(), scc[i].end());

    // for(int i = 1; i <= n; i ++) 
    //     cout << col[i] << ' ';
    for(int i = 1; i <= n ;i++) {
        if(scc[col[i]].size()) {
            for(auto v: scc[col[i]]) {
                cout << v << ' ';
            }
            cout << endl;
            scc[col[i]].clear();
        } 
    }
}