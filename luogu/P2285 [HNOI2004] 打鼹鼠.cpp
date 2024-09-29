#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int t, x, y;
};

int dis(node a, node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<node> p(m + 1);
    vector<int> dp(m + 1);
    for(int i = 1; i <= m;i ++) {
        cin >> p[i].t >> p[i].x >> p[i].y;
    }

    for(int i = 1; i <= m; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j++) {
            if(dis(p[i], p[j]) <= p[i].t - p[j].t) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    cout << *max_element(dp.begin(),dp.end()) << endl;
}