#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 5050, M = 500050, MOD = 80112002;

vector<int> p[N];
vector<int> in(N), out(N), ans(N);


void topo(int n) {
    vector<int> L;
    queue<int> S;

    for(int i = 1; i <= n;i ++) 
        if(in[i] == 0)
            S.push(i), ans[i] = 1;
    
    while(!S.empty()) {
        auto u = S.front();
        S.pop();
        for(auto v: p[u]) {
            ans[v] += ans[u];
            ans[v] %= MOD;
            if(-- in[v] == 0) {
                S.push(v);
            }
        }
    }

}

int main() {
    int n, m, res = 0;
    cin >> n >> m;
    for(int i = 1; i <= m;i ++) {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        in[y]++;
        out[x]++;
    }


    topo(n);
	for(int i = 1; i <= n; ++i)
		if(!out[i]) 
			res = (res + ans[i]) % MOD;
    cout << res % MOD << endl;
}