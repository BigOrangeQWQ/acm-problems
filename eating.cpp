#include<iostream>

using namespace std;

int main() {
    string s = "zhengzhengrichang";
    for(int i = 0; i < s.size(); i ++) {
        s[i] -= 1;
    }
    // cout << (char)('`' + 1); 
    cout << s << endl;
}