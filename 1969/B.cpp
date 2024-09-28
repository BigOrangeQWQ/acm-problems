#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
  string v;
  cin >> v;
  v = " " + v + "0";
  int n = v.length() - 1;
  int res = 0;
  // cout << 111 << endl;
  for (int l = 1, r = 0; l <= n; l++) {
    if (v[l] == '1') {
      r = max(l, r);
      for (; v[r] != '0' && r <= n; r++)
        ;
      if (r == n)
        break;
      res += r - l + 1;
      swap(v[r], v[l]);
    }
  }
  cout << res << endl;
}

signed main() {
  int T;
  cin >> T;
  while (T--)
    solve();
}

// 11000
// 10001 [5 - 2]

// 11000 [12]
// 11000 [9]

// 11000 [1 - 5] 4
// 00011 [2 - 4] 9

// 001111 [3]
// 101011 [2]
// 011011 2
// 001111 3 [5]

// 10101011
// 01101011
// 00111011
// 00011111

// 01101001
// 00111001 3 + 4 * 2