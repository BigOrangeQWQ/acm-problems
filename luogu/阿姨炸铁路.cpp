#include <iostream>
#include <vector>

using namespace std;

#define x first
#define y second

using PII = pair<int, int>;
using LL = long long;


int main() {
    int n, m;
    cin >> n >> m;
    vector<PII> p(m);
    vector<int> fa(n + 1);
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    
    for(int i = 0; i < m ; i++) 
        cin >> p[i].x >> p[i].y;


}