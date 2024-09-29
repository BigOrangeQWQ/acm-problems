#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    priority_queue<int> omg;
    for(int i = 0; i < n;i ++) {
        cin >> p[i];
    }
    int money = m;
    for(int i = 1; i < n;i ++) {
        // cout << i << " \n"[i == n - 1];
        if(money >= p[i]) {
            money -= p[i];
            omg.push(p[i]);
        }
        else if(money < p[i] && omg.size() && omg.top() > p[i]) {
            money += omg.top() - p[i]; omg.pop();
            omg.push(p[i]);
        }
        money += m;
    }
    cout << omg.size() << endl;
}

int main() {
    cin.tie(nullptr) -> ios::sync_with_stdio(false);
    int T;cin >> T;
    while(T--)  
        solve();
}