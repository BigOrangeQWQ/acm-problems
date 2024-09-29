#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long 
// vector<int> get_divisors(int x) {
//     vector<int> res;
//     for (int i = 1; i <= x / i; i ++ )
//         if (x % i == 0) {
//             res.push_back(i);
//             if (i != x / i) res.push_back(x / i);
//         }
//     sort(res.begin(), res.end());
//     return res;
// }


using namespace std;
const int N = 1e6 + 10;
int prime[100000];
bool isPrime[1000005];
void getPrime(int x){
    for (int i = 1; i < x; i += 2) {
        isPrime[i] = 1;
        isPrime[i - 1] = 0;
    }
    prime[prime[0] = 1] = 2;
    for (int i = 3; ;i += 2) {
        if(isPrime[i]) {
            int j = i*i, k = i+i;
            if(j >= x) break;
            while(j < x ) {
                isPrime[j] = 0;  j += k;
            }
        }
    }
    for (int i = 3; i < x; i += 2) {
        if(isPrime[i]) {
            prime[++prime[0]] = i;
        }
    }
}
int p[34380], cnt[34380];
void getPrimeDivisor(int x) {
    p[0] = cnt[0] = 0; int t;
    for (int i = 1; prime[i]*prime[i] <= x  && i <= prime[0]; ++i) {
        t = 0;
        while (x%prime[i] == 0) {
            ++t; x /= prime[i];
        }
        if (t) {
            p[++p[0]] = prime[i];
            cnt[++cnt[0]] = t;
        }
    }
    if (x > 1) {
        p[++p[0]] = x;
        cnt[++cnt[0]] = 1;
    }
};
vector<int> getDivisor(int x) {
    getPrimeDivisor(x);
    vector<int> divisor(1500);
    divisor[0] = 1;
    divisor[1] = 1;
    for (int i = 1; i <= p[0]; ++i) {
        int nowNum = divisor[0];
        int base = 1;
        for (int j = 1; j <= cnt[i]; ++j) {
            base *= p[i];
            for (int k = 1; k <= divisor[0]; ++k)
                divisor[++nowNum] = divisor[k]*base;
        }
        divisor[0] = nowNum;
    }
    return divisor;
}

const int MOD = 998244353;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin >> n;
    getPrime(n);
    vector<int> ans(n + 1, 0);
    ans[1] = 1;
    cout << 1 << ' ';
    for(int i = 2; i <= n;i ++) {
        ans[i] += ans[i - 1] + 1;
        ans[i] %= MOD;

        auto V = getDivisor(i);
        for(int j = 1; j <= V[0]; j++) {
            if(V[j] >= i)
                break;
            ans[i] += ans[V[j] - 1];
            ans[i] %= MOD;
        }

        cout << ans[i] % MOD << " \n"[i == n];
    }
} 