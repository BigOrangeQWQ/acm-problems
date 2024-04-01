#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
vector<int> p[N];
vector<char> cnt(N, 0);
int res[5];

bool bfs(int st) {
    queue<int> q;
    cnt[st] = 1; //色
    res[1] = 1, res[2] = 0;
    q.push(st);
    while(q.size()) {
        int u = q.front();q.pop();
        for(auto v: p[u]) {
            if(cnt[v] == cnt[u]) 
                return false;
            if(cnt[v] == 0){
                cnt[v] = cnt[u] % 2 + 1;
                res[cnt[v]] += 1; 
                q.push(v);
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m;i ++) {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) {
            if(bfs(i)) {
                res[3] += min(res[1], res[2]);
            }
            else {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << res[3] << endl;

}