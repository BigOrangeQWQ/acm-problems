#include <iostream>
#include <ostream>
#include <set>
#include <string>
#include <vector>

void solve() {
    std::string p, a, b;
    int n;
    std::cin >> p >> n >> a >> b;
    std::vector<std::set<int>> qwq(10);
    for (int i = 0; i < p.length(); i++) {
        qwq[p[i] - '0'].insert(i);
    }

    int loc = -1;
    for (int i = 0; i < n; i++) {
        int mx = loc;
        for (int j = a[i] - '0'; j <= b[i] - '0'; j++) {
            auto find = qwq[j].upper_bound(loc);
            if (find != qwq[j].end())
                mx = std::max(mx, *find);
            else {
                std::cout << "YES" << std::endl;
                return;
            }
        }
        loc = mx;
    }
    std::cout << "NO" << std::endl;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        solve();
    }
}