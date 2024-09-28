#include<iostream>

#define int long long
using namespace std;


signed main(){
    int n, L, R, k;
    cin >> n >> L >> R;

    int cnt = (n - R + (R - L - 1)) / (R - L);
    int sum = cnt * L;

    for(int i = 1; i <= n; i ++){
        int h;  cin >> h;
        sum -= min(cnt, (h - 1) / 2);
        // cout <<  min(cnt, (h - 1) / 2) << endl;
    }
    
    // if(ans < n) cout << "No" << endl;
    // else cout << "Yes" << endl;
    // return 0;
    if(sum <= 0)
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
}