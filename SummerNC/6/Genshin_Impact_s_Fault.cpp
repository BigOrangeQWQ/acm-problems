#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <map>

using namespace std;

void solve() {
    string t;cin >> t;

    if(t.find("3333333333") != string::npos) {
        cout << "invalid" << '\n';
        return;
    }

    string res = "";
    deque<char> p;
    int cnt = 0;

    for(int i = 0; i < t.length(); i ++) {
        while(p.size() >= 90) {
            if(p.front() == 'U' || p.front() == '5')
                cnt--;
            // cout << p.front() << endl;
            p.pop_front();
        }
        
        if(t[i] == 'U' || t[i] == '5'){
            cnt ++;
            res += t[i];
        }
        p.push_back(t[i]);


        if(p.size() >= 90 && cnt <= 0) {
            cout << "invalid\n";
            return;
        }
    }

    if(res.find("55") != string::npos) {
        cout << "invalid" << '\n';
        return;
    }

    cout << "valid" << "\n";
    return;
}

int main() {
    int T;cin >> T;
    while(T--)
        solve();
}