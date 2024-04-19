#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
#define endl '\n'
// int p[20200][100];
unordered_set<int> p[120];
vector<int> v[100];

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    
    int n;cin >> n;
    for(int i = 1; i <= n;i ++) {
        int w; cin >> w;
        for(int j = 1; j <= w; j++) {
            int x;cin>> x;
            if(p[i].find(x) == p[i].end()){
                // p[x][i] = true;
                p[i].insert(x);
                v[i].push_back(x);
            }
        }
    }
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        int un = 0, al = 0;
    
        for(auto i: v[a]) {
            if(p[b].find(i) != p[b].end())
                un++;
            al++;
        }
        for(auto i: v[b]) {
            if(p[a].find(i) != p[a].end())
                continue;
            al++;
        }
        
        // cout << al << ' ' << un << endl;
        // cout << un * 1.0 / al * 1.0 << endl;
        printf("%.2f%%\n", un * 1.0 / al * 1.0 * 100);
    }
}