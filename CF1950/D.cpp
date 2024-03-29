#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>


using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;
using LL = long long;
// int n;

bool check(int x) {
    while(x && x % 10 <= 1)
        x /= 10;

    if(x == 0) 
        return true;
    return false;
}

void solve() {
    int x; cin >> x;

    vector<int> hp;
    hp.push_back(101);
    hp.push_back(111);
    hp.push_back(10);
    hp.push_back(11);
    while(true) {        
        if(check(x)) {
            cout << "YES" << endl;
            return;
        }

        int flag = false;
        for(auto i: hp) {
            if(x % i == 0) {
                x /= i; 
                flag = true;
            }
        }
        if(!flag)
            break;
    }

    if(check(x))
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}

signed main() {
    int T; cin >> T;
    while(T --> 0) {
        solve();
    }
}