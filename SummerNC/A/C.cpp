#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    
    vector<int> x;
    for(int i = 1; i <= n; i ++) {
        int t, v;
        cin >> t >> v;
        while(t--){
            x.pop_back();
        }
        int ans = ((!x.empty() ? x.back() : 0) % MOD + v * (x.size() + 1) % MOD) % MOD;
        x.push_back(ans);
        cout << ans << endl;
    }
}