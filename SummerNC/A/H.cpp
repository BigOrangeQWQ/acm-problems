#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct team {
    string name;
    int solved;
    int time;
};

bool sol(team& a, team&b) {
    if(a.solved == b.solved)
        return a.time < b.time;
    return a.solved > b.solved;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    int k, n;
    unordered_set<string> c1, c2;

    cin >> k;
    vector<team> p(k);
    for(int i =0 ; i < k;i ++) {
        cin >> p[i].name >> p[i].solved >> p[i].time;
        c1.insert(p[i].name);
    }
    sort(p.begin(), p.end(), sol);

    int v;
    cin >> v;
    vector<team> vv(v);
    for(int i =0 ; i < v;i ++) {
        cin >> vv[i].name >> vv[i].solved >> vv[i].time;
        c2.insert(vv[i].name);
    }
    sort(vv.begin(), vv.end(), sol);
    // for(auto &x: vv) {
    //     cout << x.name << ' ' << x.solved << ' ' << x.time << endl; 
    // }
    
    int r1, r2;
    for(int i = k - 1; i >= 0; i--) {
        if(p[i].name == "lzr010506") {
            r1 = i;
            break;
        }
    }
    for(int i = v - 1; i >= 0; i--) {
        if(vv[i].name == "lzr010506") {
            r2 = i;
            break;
        }
    }
    for(int i = 0, ir2 = r2; i < ir2; i ++) {
        if(c1.find(vv[i].name) != c1.end()) {
            r2 --;
        }
    }
    for(int i = 0, ir1 = r1; i < ir1; i ++) {
        if(c2.find(p[i].name) != c2.end()) {
            r1 --;
        }
    }
    // cout << r1 + 1 << ' ' << r2 + 1 << endl;
    cout << min(r1 + 1, r2 + 1) << endl;
}