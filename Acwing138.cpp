#include<iostream>

using namespace std;

typedef unsigned long long ull;

const int N = 1e6 + 10;
const int P = 131;

string s;
int n;
ull f[N], p[N] = {1};

int main() {
    cin >> s >> n;
    for(int i = 1; s[i]; i ++) {
        f[i] = f[i - 1] * P + (s[i] - 'a' + 1);
        p[i] = p[i - 1] * P;
    }
    for(int i = 1; i <= n; i ++) {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if(f[r1] - f[l1 - 1] * p[r1 - l1 + 1] == 
            f[r2] - f[l2 - 1] * p[r2 - l2 + 1]) {
                cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}