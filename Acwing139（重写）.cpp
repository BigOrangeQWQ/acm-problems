#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

typedef unsigned long long ull;

const int N = 1e6 + 10;
const int P = 131;
ull f[N], fni[N], p[N] = {1};
string s;
int n;

bool check(int i, int x) {
    return f[i - 1] - f[i - x - 1] * p[x] == fni[n - i + 1] - f[n - (i + x)] * p[x];
}

string get_str(string s) {
    string str = "";
    for(int i = 0; s[i]; i ++) {
        str += '#';
        str += s[i];
    }
    str += '#';
    return str;
}

int main() {
    int t = 0;
    while(cin >> s && s != "END") {//相同为0
        s = get_str(s);
        int n = s.length();
        for(int i = 1, j = n; i <= n ; i ++, j --) {
            f[i] = f[i - 1] * P +( s[i] - 'a' + 1);
            fni[i] = fni[i - 1] * P + (s[j] - 'a' + 1); 
            p[i] = p[i - 1] * P;
        }    

        int ans = 1;
        for(int i = 1; i <= n; i ++) {
            int l = 0, r = min(i - 1, n - i);
            while(l < r) {
                int mid = (l + r + 1) / 2;
                if(check(i, mid)) l = mid;
                else r = mid - 1;
            }
            ans = max(ans, l);
        }
        printf("Case %d: %d\n", ++ t, ans);
        // cout << ans << endl;
    }    
    return 0;
}