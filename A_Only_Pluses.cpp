#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <deque>

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;

using LL = long long;

void solve() {
    vector<int> p(3);
    for(int i = 0; i < 3;i ++)
        cin >> p[i];
    
    for(int i = 1; i <= 5;i ++)
        (*min_element(p.begin(),p.end()))++;

    int sum = 1;
    for(auto i: p)
        sum *= i;
    cout << sum << endl;

}

signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}