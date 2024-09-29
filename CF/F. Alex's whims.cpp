#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    for(int i = 1; i < n; i ++) {
        cout << i << ' ' << i + 1 << endl;
        a.push_back(i);

    }
    a.push_back(n);
    b.push_back(2);
    
    while(m--) {
        int d; cin >> d; d++;
        if(d == a.size()) {
            cout << "-1 -1 -1" << endl;
        }
        else if(a.size() < d) {
            d = d - a.size();
            vector<int> pb(b.end() - d, b.end());

            int u = b[b.size() - d];
            int v1 = b[b.size() - d - 1];
            int v2 = a.back();
            for(int i = 0; i < d; i++)
                b.pop_back();
            for(auto i: pb)
                a.push_back(i);


            // while(a.size() + pb.size() < d) {
            //     pb.push_back(b.back());
            //     u = b.back();
            //     b.pop_back();
            //     v2 = b.back();
            // }
            // reverse(pb.begin(), pb.end());
            // for(auto i: pb) 
            //     a.push_back(i);
            // cout << "dbg" << endl;
            // for(auto i: a)
            //     cout << i;
            // cout << endl;
            // for(auto i: b) 
            //     cout << i;
            // cout << endl;
            cout << u << ' ' << v1 << ' ' << v2 << endl;
        }
        else {
            d = a.size() - d;
            vector<int> pb(a.end() - d, a.end());

            int u = a[a.size() - d];
            int v1 = a[a.size() - d - 1];
            int v2 = b.back();
            for(int i = 0; i < d; i++)
                a.pop_back();
            for(auto i: pb)
                b.push_back(i);
            // int u, v1, v2;
            // vector<int> pb;
            // v1 = b.back();
            // while(b.size() + pb.size() < d) {
            //     pb.push_back(a.back());
            //     u = a.back();
            //     a.pop_back();
            //     v2 = a.back();
            // }
            // reverse(pb.begin(), pb.end());
            // for(auto i: pb) 
            //     b.push_back(i);
            // cout << "dbg" << endl;
            // for(auto i: a)
            //     cout << i;
            // cout << endl;
            // for(auto i: b) 
            //     cout << i;
            // cout << endl;
            cout << u << ' ' << v1 << ' ' << v2 << endl;
        }
        // int q; cin >> q;
        // if(n == q + 1)
        //     cout << - 1 << ' ' << - 1 << ' ' << -1 << endl;
        // else 
        //     cout << q + 2 << ' ' << q + 1 << ' ' << 2 << endl; 
    }
}

int main() {
    int T; cin >> T;
    while(T--)
        solve();
}
