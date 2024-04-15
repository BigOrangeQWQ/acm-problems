#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 5e4 + 10;
vector<string> m(N);
vector<int> p(N);
map<string, int> mp;
int tot;

int find(int x) {
    if(p[x] != x)
        return p[x] = find(p[x]);
    return p[x];
}

int main() {
    char c;
    string name;
    for(int i = 1; i <= N - 1;i ++)
        p[i] = i;

    int last = 0;
    while(1) {
        cin >> c;
        if(c == '$')
            break;
        cin >> name;
        if(mp.find(name) == mp.end()) 
            mp[name] = ++tot, m[tot] = name;

        if(c == '+') {
            p[find(mp[name])] = find(last);
        }
        else if(c == '#')
            last = mp[name];
        else if(c == '?')
            cout << name << ' ' << m[find(mp[name])] << endl;
    }
}