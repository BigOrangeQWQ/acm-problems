#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

const int N = 1e6 + 10;
const int P = 131;
unsigned long long f[N], fni[N], p[N] = {1};
int n;
char s[N];
// char s;

// ull hash1(int l, int r) {
//     return f[r] - f[l - 1] * p[r - l + 1];
// }

// ull hash2(int l, int r) {
//     return fni[l] - fni[r + 1] * p[r - l + 1];
// }

bool check1(int t, int x) {
    return f[t - 1] - f[t - x - 1] * p[x] == fni[t + 1] - fni[t + x + 1] * p[x]; 
}

bool check2(int t, int x) {//偶长度，中心t 单边x
    return f[t - 1] - f[t - x - 1] * p[x] == fni[t] - fni[t + x] * p[x];
}

int main() {
    int cnt = 0;
    while(cin >> (s + 1) && strcmp((s + 1), "END")) {
        n = strlen(s + 1);
        fni[n + 1] = 0;
        for(int i = 1, j = n; i <= n; j --, i ++) {
            f[i] = f[i - 1] * P + (s[i] - 'a' + 1);
            fni[j] = fni[j + 1] * P + (s[j] - 'a' + 1);
            p[i] = p[i - 1] * P;
        } 

        int ans = 1;

        for(int i = 1; i <= n; i ++) { //中心点
            // cout << s[i] << endl;
            int l = 0, r = min(i - 1, n - i);
            while(l + 1 < r) {
                int mid = (l + r) / 2;
                if(check1(i, mid)) l = mid;
                else r = mid;
            }
            ans = max(ans, 2 * l + 1);

            l = 0, r = min(i - 1, n - i + 1);
            while(l + 1 < r) {
                int mid = (l + r) / 2;
                if(check2(i, mid)) l = mid;
                else r = mid;
            }
            ans = max(ans, 2 * l);
        }

        cout << "Case " << ++cnt << ": " << ans << endl;
    }
    return 0;
}
