
#include<bits/stdc++.h>
using namespace std;
#define enl , writestr("\n")
#define int long long
#define endl "\n"
#define PII pair<int, int>
#define ULL unsigned long long
#define xx first
#define yy second
#define PI acos(-1)
const int P = 131;//131,13331
const int N = 5e6 + 10;
const int M = 1e3 + 10;
const int INF = 1e18;
const int ENF = -1e18;
const int mod = 1e9 + 7;//998244353
const double feps = 1e-6;
void ClearFloat() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }int read() { int ret = 0, f = 1; char ch = getchar(); while ('0' > ch || ch > '9') { if (ch == '-')f = -1; ch = getchar(); }while ('0' <= ch && ch <= '9') { ret = ret * 10 + ch - '0'; ch = getchar(); }return ret * f; }int gcd(int a, int b) { if (b) while ((a %= b) && (b %= a)); return a + b; }int lcm(int a, int b) { return a * b / gcd(a, b); }int lowbit(int x) { return x & (-x); }
int T, n, m, h[310][M * 100], h1[N], q, k, p[N], ans;
string s;
int find(int i, int l, int r)//返回已知的字符串哈希
{
    return h[i][r] - h[i][l - 1] * p[r - l + 1];
}
int find1(int l, int r)//返回被询问的字符串哈希
{
    return h1[r] - h1[l - 1] * p[r - l + 1];
}
bool check(int i, int l, int r)//比较从l到r区间的字符串是否相同
{
    return find(i, l, r) == find1(l, r);
}
void slove()
{
    cin >> n >> q >> m >> k;
    p[0] = 1;
    for (int i = 1; i <= N / 10; i++) p[i] = p[i - 1] * P;
    cout << p[1010] << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> s;
    //     for (int j = 1; j <= s.size(); j++)
    //     {
    //         h[i][j] = h[i][j - 1] * P + s[j - 1];
    //     }
    // }
    // while (q--)
    // {
    //     cin >> s; int res = 0;
    //     for (int i = 1; i <= s.size(); i++) h1[i] = h1[i - 1] * P + s[i - 1];
    //     for (int i = 0; i < n; i++)
    //     {
    //         int now = 0;
    //         for (int j = 1; j <= m; j++)
    //         {
    //             if (!check(i, j, j))
    //             {
    //                 now++;
    //                 if (now > k) break;
    //             }
    //             int l = j, r = m;
    //             while (l < r)//减少遍历方式
    //             {
    //                 int mid = l + r + 1 >> 1;
    //                 if (check(i, l, r)) l = mid;//如果该区间内没有不同，那么l跳转至mid
    //                 else r = mid - 1;//否则r向前跳转
    //             }
    //             j = l;//另j=l，减少遍历数量
    //         }
    //         if (now <= k) res++;
    //     }
    //     cout << res << endl;
    // }
}  
signed main()
{
    ClearFloat();
    T = 1;
    //cin >> T;
    for (int i = 1; i <= T; i++)
    {
        slove();
    }
}