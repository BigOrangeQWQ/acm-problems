#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int N = 1e6 + 10, M = 1e5 + 10;
string s[N];
int tree[N][26];
int idx;

void insert(string s) {
    int p = 0;
    for(int i = 0; s[i]; i ++) {
        int x = s[i] - '0';
        if(!tree[p][x]) tree[p][x] = ++ idx;
        p = tree[p][x];
    }

}

string query(string s) {
    string str = "";

    int p = 0;
    for(int i = 0; s[i]; i ++) {
        int x = s[i] - '0';
        if(tree[p][(x ^ 1)]) {
            str += '1';
            p = tree[p][(x ^ 1)];
        }
        else {
            str += '0';
            p = tree[p][x];
        }
    }    
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        string str = "";
        while(x) {
            str += (x & 1 ? '1' : '0');
            x /= 2; 
        }
        // cout << str << endl;
        int l = str.length();
        for(int j = 0; j < 31 - l; j ++) {
            str += '0';
        }
        
        reverse(str.begin(), str.end());
        // cout << str << endl;
        s[i] = str;
        insert(s[i]);
    }


    // string s = query();
    int ans = -1;
    for(int i = 1; i <= n; i ++) {
        string str = query(s[i]); //s[i]能匹配到的MAX异或

        int res = 1, sum = 0;
        for(int j = 0; str[j]; j ++) {
            if(str[j] == '1') sum += res;
            res *= 2;
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}