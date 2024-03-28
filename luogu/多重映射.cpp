#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
const int M = 1e6 + 10;

int a[N], b[M];

// int find(int x) {
//     if(x != p[x]) return p[x] = find(p[x]);
//     return p[x];
// }

int main() {
    int T; cin >> T;


    while(T --) {
        int n, m;
        cin >> n >> m;
        // for(int i = 0; i <= M; i ++) b[i] = i;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
            b[a[i]] = a[i];
        }

        vector<PII> p;
        while(m --) {
            int x, y;
            cin >> x >> y;
            p.push_back({x, y});
        }
        reverse(p.begin(), p.end());

        for(auto t : p) {
            // cout << t.x << ' ' << t.y << endl;
            if(!b[t.y]) b[t.y] = t.y;
            b[t.x] = b[t.y];
        }

        for(int i = 0; i < n; i ++) {
            cout << b[a[i]] << " \n"[i == n - 1];
        }
            
        for(auto t : p) {
            b[t.x] = t.x;
            b[t.y] = t.y;
        }
    }
}