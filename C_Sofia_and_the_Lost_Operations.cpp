#include <iostream>
#include <algorithm>
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
#define int long long

// 首先我们可以获得原始数组和操作后数组
// 第二我们有操作序列可以给出
// 我们会发现其中有巨多的无用操作，
// 如果这个数存在于b数组中，则有用，直接覆盖到对应的值上面。
// 如果这个数不存在b数组中则需要有一个元素献身，
// 就是说a和b数组里面不一样的元素取出来，然后操作数组有没有这两个相同的，
// 然后操作数组需要按顺序来
// 如果我操作到最后一个元素它不是b数组里面的元素，就false
// 否则True


using PII = pair<int, int>;

using LL = long long;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0;i < n;i ++) 
        cin >> a[i];
    for(int i = 0;i < n;i ++) 
        cin >> b[i];
    
    multiset<int> mp;
    for(int i = 0;i < n;i ++) {
        if(a[i] != b[i]) 
            mp.insert(b[i]);
    }
    // if(mp.empty()) {
    //     cout << "YES" << endl;
    //     return;
    // }

    cin >> m;
    vector<int> p(m);
    bool flag = false;
    for(int i = 0; i < m;i ++){
        cin >> p[i];
    }

    for(int i = 0; i < m;i ++){
        auto res = mp.find(p[i]);
        if(res != mp.end()) {
            mp.erase(res);
        }
    }

    for(int i = 0; i < n;i ++) {
        if(b[i] == p[m - 1]){
            flag = true;
            break;
        }
    }
    // cout << mp.size() << ' ' << flag  << endl;
    if(mp.size() || flag == false) 
        cout << "NO" << endl;
    else 
        cout << "YES" << endl;
}


signed main() {
    int T;cin >> T;
    // int T = 1;
    while(T --> 0) {
        solve();
    }
}