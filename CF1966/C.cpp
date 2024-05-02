#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

// void solve() {
//     int n;cin >> n;
    // set<int> p;
    // priority_queue<int, vector<int>, greater<int>> q;
    // for(int i = 1; i <= n;i ++) {
    //     int x;cin >> x;
    //     p.insert(x);
    // }
    // for(auto i: p)
    //     q.push(i);

    // int res = 0,  sumx = 0; //操作次数，累计扣除大小
    // // int flag = q.top() % 2 == 0 && q.top() > 1;
    // int flag = q.top();
    // while(!q.empty()) {
    //     if(q.size() && q.top() - sumx <= 0){
    //         q.pop();
    //         continue;
    //     }
    //     sumx += q.top() - sumx;  q.pop();
    //     res ++;
    // }
    // cout << flag << ' ' << sumx << ' ' << sumx - flag + 1 << ' '<< res  << endl;
    // if(flag > 1 && (sumx % 2 == 1 || (sumx - flag + 1) % 2 == 1))
    //     cout << "Alice" << endl;
    // else 
    //     cout << "Bob" << endl;
// } 

// void SG() {
//     int n; cin >> n;
//     set<int> p;
//     p.insert(0);
//     for(int i = 1; i <= n;i ++) {
//         int x; cin >> x;
//         p.insert(x);
//     }

//     vector<int> v(p.begin(), p.end());
//     reverse(v.begin(), v.end());
    
//     vector<int> w;
//     for(int i = 1; i + 1 < v.size(); i ++) {
//         w.push_back(v[i] - v[i + 1]);
//     }
    
//     for(int &i: w) {
//         i = min(i, 3);
//     }

//     auto mex = [](vector<int> v, int n) {
//         vector<int> q(n);
//         for(auto i: v) {
//             if(i < n)
//                 q[i]++;
//         }
//         for(int i = 1; i <= n; i++) {
//             if(q[i] == 0)
//                 return i;
//         }
//         return -1;
//     };

//     vector<int> run;
//     run.push_back(0);
//     for(auto v: w) {
//         for(int i = 1; i <= v;i ++) {
//             run.push_back(mex(run, n));
//             cout << i << ' ' << v << ' ' << run.back() << endl;

//         }
//         run = {run.back()};
//     }
//     cout << run.back() << endl;
// }

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n ;i ++)   
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for(int i = n; i ;i --) 
        b[i] = a[i] - a[i - 1];

    int r = 1;
    for(int i = 1; a[i] != a[n]; i ++) {
        if(b[i] == 0) continue;
        if(b[i] != 1) break;
        r ^= 1;
    }
    cout << (r ? "Alice" : "Bob") << endl;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) 
        // SG();
        solve();
}