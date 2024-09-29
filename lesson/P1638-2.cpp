#include <iostream>
#include <deque>
#include <vector>
#include <map>

using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> p[i];
    
    int len = (1 << 30) - 1;
    pair<int, int> ans;

    deque<int> q;
    map<int, int> mp; // 维护每个数在这个区间里出现的次数的区间

    for(int i = 1; i <= n; i ++) { 
        q.push_back(i); // r++
        mp[p[i]] ++; 

        // 如果队列不为空，然后 左端点的出现次数大于1 就把它删掉
        while(!q.empty() && mp[p[q.front()]] > 1) { // 尝试 l ++ 
            mp[p[q.front()]] --;
            q.pop_front();
        }

        // 更新答案，你当前的维护的区间长度如果小于原长度就更新答案
        if(mp.size() >= m && q.size() < len) {
            len = q.size();
            ans = {q.front(), q.back()};
        }
    }

    cout << ans.first << ' ' << ans.second << endl;
}

int main() {
    // int T;cin >> T;
    int T = 1;
    while(T--)
        solve();
}