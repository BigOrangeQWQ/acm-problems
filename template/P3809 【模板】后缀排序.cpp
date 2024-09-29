#include <iostream>
#include <algorithm>
#include <cstring>
// #include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int N = 2e6 + 10;
const int P = 131;

ull f[N], p[N] = {1}, s[N];
char str[N];
int len;

ull get(int l, int r) {
    return f[r] - f[l - 1] * p[r - l + 1];
}

int gmcp(int a, int b) {
    int l = 0, r = len - max(a, b) + 1, mid;
    while(l < r) {
        mid = (l + r + 1) >> 1;
        if(get(a, a + mid - 1) == get(b, b + mid - 1)) l = mid;
        else r = mid - 1;
    }
    return l;
}

bool cmp(int a, int b) {
    int l = gmcp(a, b);
    int av = a + l > len ? -3 : str[a + l];
    int bv = b + l > len ? -3 : str[b + l];
    return av < bv;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> (str + 1);
    len = strlen(str + 1);

    p[0] = 1;
    for(int i = 1; i <= len; i ++) {
        f[i] = f[i - 1] * P + (str[i] - 'a' + 1);
        p[i] = p[i - 1] * P;
        s[i] = i;
    }

    sort(s + 1, s + 1 + len, cmp);

    for(int i = 1; i <= len; i ++) {
        cout << s[i] << " \n"[i == len];
    } 
    return 0;
}