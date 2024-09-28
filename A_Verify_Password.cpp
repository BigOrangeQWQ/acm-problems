#include <iostream>

using namespace std;

void solve(){ 
    int n;cin >> n;
    string s;cin >> s;
    int flag = 0; // 
    char last = s[0];
    for(auto c: s) {
        if(c >= 'a' && c <= 'z'){
            flag = 1;
            if(last >= 'a' && last <= 'z' && last > c) {
                cout << "NO" << endl;
                return;
            }
        }
        if(c >= '0' && c <= '9') {
            if(flag) {
                cout << "NO" << endl;
                return;
            }
            if(last >= '0' && last <= '9' && last > c) {
                cout << "NO" << endl;
                return;
            }
        }
        last = c;
    }
    cout << "YES" << endl;
}

int main() {
    int T;cin >> T;
    while(T--)
        solve();
}