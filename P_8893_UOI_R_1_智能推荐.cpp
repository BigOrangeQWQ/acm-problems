#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 5e5 + 10;
vector<int> G[N];
vector<int> in(N);
int ans = -1, n, k;

queue<pair<int,int>> S;

void topo() {

    // for(int i = 0; i <= n + 1;i ++) 
    //     if(in[i] == 0) 
    //         S.push({i, 0});
    
    while(S.size()) {
        auto x = S.front(); S.pop();
        if(x.first == k) {
            ans = x.second;
            return;
        }

        for(auto v: G[x.first]) {
            if(-- in[v] == 0) {
                S.push({v, x.second + 1});
            }
        }

    }
    
}

int main() {
    int p;
    cin >> n >> k >> p;
    for(int i = 1; i <= p;i ++) {
        int x;
        cin >> x;
        S.push({x, 0});
    }

    int q; cin >> q;
    for(int i = 1; i <= q;i ++) {
        int x, y, z;
        cin >> x >> y;
        for(int i = 1; i <= y; i ++) {
            cin >> z;
            G[z].push_back(x);
            in[x]++;
        }
    }
    topo();
    cout << ans << endl;
}