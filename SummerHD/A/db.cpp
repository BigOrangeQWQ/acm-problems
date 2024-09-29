#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int n , k;
    cin >> n >> k;

    set<int> x;
    map<int, set<int>> p;
    map<int, set<pair<int,int>>> p2;
    int ans = 0, cnt = 0;
    for(int a = 0; a <= ((1 << k) - 1); a ++ ) {
        for(int b = 0; b <= ((1 << k) - 1); b++) {
            for(int c = 0; c <= ((1 << k) - 1); c++) {
                for(int d= 0; d <= ((1 << k) - 1); d++) {
                    cnt++;
                    if((((a & b) ^ c) | d) == n) {
                        cout << a << ' ' << b << ' ' << c << ' ' << d << ' '<< (((a & b) ^ c) | d) << endl;
                        ans++;
                        x.insert(c);
                        p[d].insert(c);
                        p2[d].insert({a,b});
                    }
                }
            }
        }
    }
    cout << ans << ' ' << x.size() << ' ' << cnt << endl;
    for(auto x: p) {
        cout << x.first << ' ' << x.second.size() << endl;
    }
    cout << endl;
    for(auto x: p2) {
        cout << x.first << ' ' << x.second.size() << endl;
    }
}