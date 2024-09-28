#include <iostream>

using namespace std;

void solve() {
    int n; cin >> n;
    cout << (n / 4) + (n % 4 / 2) << endl;
}

int main() {
    int T;cin >> T;
    while(T--) 
        solve();
}