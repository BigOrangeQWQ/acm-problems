#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <map>
#include <deque>

using namespace std;

#define x first
#define y second
#define endl '\n'
// #define int long long

using PII = pair<int, int>;

using LL = long long;
vector<int> p((int) 1e6 + 10);
int n, m;
PII ans;

bool check(int l) {
    unordered_map<int, int> mp;
    deque<int> q;
    int cnt = 0;

    for(int i = 1; i <= l; i++) {
        q.push_back(p[i]);
        if(!mp[q.back()]) 
            cnt ++;
        mp[q.back()] ++;
    }
    if(cnt >= m){
        ans = {1, l};
        return true;
    }

    for(int i = l + 1; i <= n; i++) {
        if(mp[q.front()]) 
            mp[q.front()] --;

        if(!mp[q.front()])
            cnt --;
        q.pop_front();

        q.push_back(p[i]);
        if(!mp[q.back()]) 
            cnt ++;
        mp[q.back()] ++;

        if(cnt >= m){
            ans = {i - l + 1, i};
            return true;
        }

    }
    return false;
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i =1; i <= n;i ++) {
        cin >> p[i];
    }

    int l = 0, r = n + 1;
    while(l  < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << ans.x << ' ' << ans.y << endl;
}

signed main() {
    int T = 1;
    while(T --> 0) {
        solve();
    }
}