#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 20;
vector<int> dis(N);
vector<int> E[N];

// int find(int x) {
//     if(x == p[x])
//         return p[x];
//     else 
//         return p[x] = find(p[x]);
// }

void bfs(int u) {
    // if(dis[u])
}

int main() {
    int n, m;
    cin >> n >> m;
    // for(int i = 1; i <= n;i ++) {
    //     p[i] = i;
    // }
    for(int i = 1; i <=m ; i++) {
        int x,y ;
        cin>> x >>y;
        E[x].push_back(y);
    }
    
}