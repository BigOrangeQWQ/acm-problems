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
    int n, c;
    cin >> n;
    priority_queue<int> big; //存比mid小的
    priority_queue<int, vector<int>, greater<int>> small; //存比mid大的

    cin >> c;
    big.push(c);
    cout << c << endl;

    for(int i = 2;i <= n;i ++) {
        cin >> c;
        (c > big.top()) ? small.push(c) : big.push(c);

        if(i % 2 == 1) {
            while(abs((int)big.size() - (int)small.size()) > 1) {
                if(big.size() > small.size()) {
                    small.push(big.top());
                    big.pop();
                }
                else {
                    big.push(small.top());
                    small.pop();
                }
            }
            
            if(big.size() > small.size())
                cout << big.top() << endl;
            else 
                cout << small.top() << endl;
        }
    }
}

signed main() {
    // int T;cin >> T;
    int T = 1;
    while(T --> 0) {
        solve();
    }
}