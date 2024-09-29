#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    if(n % 2 == 0 && n / 2 == k) {
        cout << n << endl;
        return 0;
    }

    if(k > n / 2) 
        k = n - k;

    cout << 1 + n * k << endl;
}