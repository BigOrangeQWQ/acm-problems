#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; string s;
    cin >> s;

    vector<int> x1, x2;
    for(int i = 0 ;i < s.length();i++) {
        if(s[i] == '(') {
            x1.push_back({i});
        }
        else if(s[i] == ')' && x1.size()) {
            x1.pop_back();
            
        }
        
    }
}

int main() {
    int T; cin >> T;
    while(T--) {
        solve();
    }
}