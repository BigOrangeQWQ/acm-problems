#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);  
    cin.tie(nullptr); 
    
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
		vector<ll> f(k + 10, 1e12);
        f[0] = 0;
        for(int i = 0; i < n; i++ ) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            for(int j = k; j >= 0; j--) {
                if(j <= k - 1) f[j + 1] = min(f[j + 1], f[j] + a);
                if(j <= k - 2) f[j + 2] = min(f[j + 2], f[j] + b);
                if(j <= k - 3) f[j + 3] = min(f[j + 3], f[j] + c);
                if(j <= k - 4) f[j + 4] = min(f[j + 4], f[j] + d);
            }
        }
        cout << f[k] << '\n';
    }
    return 0;
}