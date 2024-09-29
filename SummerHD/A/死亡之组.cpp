#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

void solve() {
    int n, L, D;
    cin >> n >> L >> D;
    vector<int> p(n), ans;
    for(int i = 0 ; i < n; i++)
        cin >> p[i];
    ans.push_back(p[0]);
    sort(p.begin() + 1, p.end());
    if(ans[0] >= L) {
        for(int i = 1; i <= 3; i ++) {
            ans.push_back(p[i]);
        }
    }
    if(ans[0] < L) {
        ans.push_back(p.back());
        for(int i = 1; i <= 2; i ++) {
            ans.push_back(p[i]);
        }
    }

    int cnt = 0;
    for(int i = 0; i < 4; i++) 
        if(ans[i] >= L)
            cnt ++ ;
    if(cnt >= 2) {
        cout << "No" << endl;
        return;
    }  
    if(*max_element(ans.begin(),ans.end()) - *min_element(ans.begin(), ans.end()) <= D) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    return;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    int T;cin >> T;
    while(T--)
        solve();
}