#include <iostream>
#include <vector>

#define endl '\n'
#define int long long

using namespace std;

int n;
const int N = 3e5 + 10;
vector<int> a(N), b(N);

bool check(int mid) {
    int cnt = 0, ans = 0;
    for(int i = 1; i <= n;i ++) {
        if(a[i] >= mid) cnt++;
    }

    vector<int> sumc(n + 5), cst(n + 5), maxv(n + 5);

    for(int i = 1; i <= n; i++) {
        if(a[i] < mid && b[i] >= mid) cst[i] = 1;
        else if(a[i] >= mid && b[i] < mid) cst[i] = -1;
        else cst[i] = 0;
    }

    sumc[0] = 0;
    for(int i = 1; i <= n;i ++) {
        sumc[i] = sumc[i - 1] + cst[i];
    }

    maxv[n] = sumc[n]; 
    for(int i = n - 1; i >= 1; i--) {
        maxv[i] = max(maxv[i + 1], sumc[i]);
    }
    ans = cnt;
    for(int l = 0; l < n; l ++) {
        ans = max(ans, maxv[l + 1] - sumc[l] + cnt);
    }
    return ans >= (n + 1) / 2;
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    int l = 1, r = 2e9;
    while(l + 1 < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
}