#include <iostream>
#include <vector>

using namespace std;


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    int E = 0, Q = 0;
    for(int i = 0; i < n ;i ++) 
        cin >> a[i];
    for(int i = 0; i < n ;i ++) 
        cin >> b[i];
    for(int i = 0; i < n ;i++) {
        if(a[i] == b[i]) 
            E++;
        if(a[i] > b[i])
            Q++;
    }
    cout << (E + 1) / 2 + Q << "\n";
}

int main() {
    int T;cin >> T;
    while(T--)
        solve();
}