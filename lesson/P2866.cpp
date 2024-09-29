#include <iostream>
#include <deque>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> cow(n);

    for(int i = 0; i < n; i ++) 
        cin >> cow[i];
    
    long long ans = 0;
    deque<int> q;

    for(int i = 0; i < n; i ++) {
        while(!q.empty() && cow[q.back()] <= cow[i]) {
            q.pop_back();
        }
        ans += q.size();
        cout << q.size() << endl;
        q.push_back(i);
    }

    cout << ans << endl;
}

int main() {
    // int T; cin >> T;
    int T = 1;
    while(T--)  
        solve();
}