#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
vector<int> G[N]; // 边
vector<pair<int,int>> p[N]; // 每个点的度
vector<int> primes; vector<bool> st;     

void get_primes(int n) {
    st.resize(N + 1);
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j ++ ) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int n; cin >> n;
    
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr);
}