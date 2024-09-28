#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int loc = max_element(p.begin(), p.end()) - p.begin();
    int res = *max_element(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && res <= p[i]) {
            loc = i;
            break;
        }
    }

    for (int i = loc; i >= 0; i -= 2) res++;
    for (int i = loc + 2; i < n; i += 2) res++;
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}