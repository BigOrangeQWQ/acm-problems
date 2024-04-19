#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;
unordered_map<string, int> value0, value1, value2; //值
unordered_map<string, string> next0, next1, next2; //next node

#define endl '\n'
int cnt[100010]; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string st; int n;
    cin >> st >> n;
    for(int i = 1; i <= n;i ++) {
        string a;int v; string n;
        cin >> a >> v >> n;
        value0[a] = v;
        next0[a] = n;
    }
    string last1 = "st1";
    string last2 = "st2";
    const int inf = 1e9;
    value1[last1] = value2[last2] = inf;
    next1[last1] = next2[last2] = "-1";

    string now = st;
    while(true) {
        if(now == "-1")
            break;
        int v = value0[now];
        string nxt = next0[now];
        if(!cnt[abs(v)]) {
            // cnt.insert(abs(v));
            cnt[abs(v)] = true;
            next1[now] = next1[last1];
            next1[last1] = now;
            value1[now] = v;
            last1 = now;
        }
        else {
            next2[now] = next2[last2];
            next2[last2] = now;
            value2[now] = v;
            last2 = now;
        }
        now = nxt;
    }

    now = "st1";
    while(true) {
        if(now == "-1")
            break;
        if(now != "st1")
            cout << now  << ' ' << value1[now] << ' ' << next1[now] << endl;
        now = next1[now];
    }
    now = "st2";
    while(true) {
        if(now == "-1")
            break;
        if(now != "st2")
            cout << now  << ' ' << value2[now] << ' ' << next2[now] << endl;
        now = next2[now];
    }
}