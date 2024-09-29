#include <iostream>
#include <set>
#include <queue>
#include <unordered_set>


using namespace std;

using PII = pair<int, int>;

string to_str(PII x) {
    return to_string(x.first) + "_" + to_string(x.second); 
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (nullptr);

    int n, m, ans;
    cin >> n >> m;
    ans = n;

    set<PII> rla; //关系
    set<PII> good; //区间
    queue<PII> S;

    for(int i = 1; i <= m ;i ++) {
        int x, y;
        cin >> x >> y;
        rla.insert({min(x,y), max(x, y)});
        if(min(x, y) == max(x, y) - 1){
            good.insert({min(x,y), max(x, y)});
            S.push({min(x,y), max(x, y)});    
        }
    }

    while(!S.empty()) {
        auto u = S.front(); S.pop();
        int r = u.second - u.first;

        if(good.find({u.first + 1, u.second + 1}) != good.end() && 
            rla.find({u.first, u.second + 1}) != rla.end()) {
            good.insert({u.first, u.second + 1});
            S.push({u.first, u.second + 1});
        }
    }
    cout << good.size() + n << endl;
}
