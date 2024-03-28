#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> e(N);

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) 
        e[i] = i;
    
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
    }
}