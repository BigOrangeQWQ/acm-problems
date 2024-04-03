#include <algorithm>
#include <iostream>

using namespace std;


int main() {
    string a, b;
    int res = 1;
    cin >> a >> b;
    for(int i = 0;i < a.length() - 1; i ++) {
        string c = a.substr(i, 2);
        reverse(c.begin(), c.end());
        if(b.find(c) != string::npos)
            res <<= 1;
    }
    cout << res << endl;
}