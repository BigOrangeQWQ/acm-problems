#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using PII = pair<int,int>;
vector<pair<int,int>> E[800];
vector<int> dis(800), peores(800),
        peo(800), cnt(800),
        pre(800), ljcnt(800);


int res = 0, lj = 0;
vector<int> ljd;
void counting(int ed) {
    // cout << ed << ' ';
    // res += peo[ed];
    ljd.push_back(ed);
    if(pre[ed] != -1)
        counting(pre[ed]);
}

int dj(int st, int ed) {
    fill(dis.begin(), dis.end(), 1e9);
    fill(pre.begin(), pre.end(), -1);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, st});
    
    dis[st] = 0;
    peores[st] = peo[st];
    ljcnt[st] = 1;
    // cnt[st] = true;
    while(q.size()) {
        auto x = q.top().second;q.pop();

        if(cnt[x])
            continue;
        cnt[x] = true;

        for(auto p: E[x]) {
            int endp = p.second;
            int v = p.first;

            if(dis[x] + endp < dis[v]) {
                dis[v] = dis[x] + endp;
                peores[v] = peores[x] + peo[v];
                pre[v] = x;
                ljcnt[v] = ljcnt[x];
                q.push({dis[v], v});
            }
            else if(dis[x] + endp == dis[v]) {
                
                ljcnt[v] += ljcnt[x];
                if(peores[v] < peores[x] + peo[v]) {
                    peores[v] = peores[x] + peo[v];
                    pre[v] = x;
                }
            }

        }
    }
    return dis[ed];
}

int main() {
    int N, M, S, D;
    cin >> N >> M >> S>> D;
    for(int i = 0; i < N;i ++){
        cin >> peo[i]; 
        // peores[i] = peo[i];
    }
    for(int i = 1; i <= M;i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        E[x].push_back({y, z});
        E[y].push_back({x, z});
    }
    int d = dj(S, D);
    counting(D);
    cout << ljcnt[D] << ' ' << peores[D] << endl;
    for(int i = ljd.size() - 1; i >= 0; i --)
        cout << ljd[i] << " \n"[i == 0];
}