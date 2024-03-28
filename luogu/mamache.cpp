#include<iostream>
#include <vector>
#include <set>
#define endl '\n'
#define fst first 
#define snd second 

using namespace std;

vector<int> manacher(string s) {
    string t = "$";
    for(auto c : s) {
        t += string("#") + c;
    }
    t += "#^";
    
    cout << t << endl;
    
    int n = t.size();
    vector<int> p(n);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i ++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i] ++;
        }
        if(i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 2, end(p) - 2);
}


// vector<int> manacher_odd(string s) {
    // int n = s.size();
    // s = "$" + s + "^";
    // vector<int> p(n + 2);
    // int l = 1, r = 1;
    // cout << s << endl;
    
    // for(int i = 1; i <= n; i++) {
        // p[i] = max(0, min(r - i, p[l + (r - i)]));
        // while(s[i - p[i]] == s[i + p[i]]) {
            // p[i]++;
        // }
        // if(i + p[i] > r) {
            // l = i - p[i], r = i + p[i];
        // }
    // }
    // return vector<int>(begin(p) + 1, end(p) - 1);
// }
// 
// vector<int> manacher(string s) {
    // string t;
    // for(auto c: s) {
        // t += string("#") + c;
    // }
    // auto res = manacher_odd(t + "#");
    // return vector<int>(begin(res) + 1, end(res) - 1);
// }

void solve() {
    string s;
    int n, q;
    cin >> n >> q;
    cin >> s;
    auto p = manacher(s);
    // for(auto x : p) {
        // cout << x << ' ';
    // }
    cout << endl;
    // for(auto &x : p) x --;
    
    set<int> s1, s2;
    for(int i = 0; i < n - 1; i ++) {
        if(s[i] != s[i + 1]) s1.insert(i);
        if(i != n - 1 && s[i] != s[i + 2]) s2.insert(i);
    }
    
    while(q --) {
        int l, r;
        cin >> l >> r;
        l --, r --;
        
        if(l == r) {
            cout << 0 << endl;
            continue;
        }
        
        // int len = r - l + 1;
        
        // int ans = 0;
        // auto j = s1.lower_bound(l);
        // if(j == s1.end() || (*j) >= r) {
        //     ans = 0;
        // } //全字符相同,全是回文串 
        // else {
        //     j = s2.lower_bound(l);
        //     if(j == s2.end() || (*j) >= r - 1) {
        //         ans = ((len - 1) / 2) * (((len - 1) / 2) + 1);
        //     }//交替字符串
        //     else {
        //         ans = len * (len - 1) / 2 - 1; //减掉长度为1的串
        //     }
        // }
        
        // if(p[l + r] < (r - l + 1)) ans += len;
        
        // cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; cin >> T;
    while(T --) {
        solve();        
    }
    
    return 0;
}