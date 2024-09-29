#include <iostream>

using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    string s[n + 1];
    for(int i = 1; i <= n;i ++)  {   
        string x;cin >> x;
        s[i] = " " + x;
    }
    
    for(int i = 1; i <= n; i += k) {
        for(int j = 1; j <= n; j += k){
            cout << s[i][j];
        }
        cout << '\n';
    }
}

int main() {
    int T;cin >> T;
    while(T--)
        solve();
}