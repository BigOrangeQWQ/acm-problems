
#include <algorithm>
#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        std::cin >> x;
        p[i] = {x, i};
    }
    std::sort(p.begin() + 1, p.end());
}
int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}