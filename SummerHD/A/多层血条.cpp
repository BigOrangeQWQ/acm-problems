#include <iostream>
#include <vector>

using namespace std;

void phead(int v) {
    cout << "+";
    for(int i = 1; i <= v;i ++) 
        cout << "-";
    cout << "+\n";
}

void solve() {
    int n, m, hp, dmg;
    cin >> n >> m >> hp >> dmg;

    vector<char> ans(m, ' ');

    int k = min(((hp + (m - 1)) / m), 5); //至多五条

    // hpx 为 剩下五条的血量从哪开始
    auto hpx = max(hp - (5 * m), 0);

    // cout << hpx << ' ' << k << ' ' << hp << endl;
    for(int i = 0; i < k; i ++) {
        for(int j = 1; j <= n; j ++) {
            for(int z = 1; z <= m && hpx < hp; z++, hpx++) {
                if(hpx > hp - dmg - 1 && hpx < hp)
                    ans[hpx % m] = '.';
                    // ans.push_back('.');
                else 
                    ans[hpx % m] = 'A' + (hpx / m % 5);
                    // ans.push_back('A' + (i % 5));
            }
        }
    }
    phead(m);
    for(int i = 0 ; i < n; i++) {
        cout << "|";
        for(auto c: ans) 
            cout << c;
        cout << "|\n";
    }
    phead(m);
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    int T;cin >> T;
    while(T--)
        solve();
}