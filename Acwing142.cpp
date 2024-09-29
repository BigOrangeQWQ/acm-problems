#include<iostream>

using namespace std;

const int N = 2e6 + 10;
int tree[N][26], cnt[N];
int idx;

void insert(string s) {
    int p = 0;
    for(int i = 0; s[i]; i ++) {
        int x = s[i] - 'a';
        if(!tree[p][x]) tree[p][x] = ++ idx;
        p = tree[p][x];
    }
    cnt[p] ++;
}

int query(string s) {
    int p = 0, ans = 0;
    for(int i = 0; s[i]; i ++) {
        int x = s[i] - 'a';
        ans += cnt[p];
        p = tree[p][x];
        if(p == 0) return ans;
    }
    ans += cnt[p];
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    while(n --) {
        string s;
        cin >> s;
        insert(s);
    }
    while(m --) {
        string s;
        cin >> s;
        cout << query(s) << endl;
    }
    return 0;
}   