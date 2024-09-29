#include <iostream>

using namespace std;

int main() {
    string s[9];
    for(int i = 0; i < 9; i++) {
        cin >> s[i];
    }
    for(int i = 1, f = 1; i < 8 && f; i ++) {
        for(int j = 1; j < 8; j ++) {
            if(s[i][j] == '8'){
                s[i][j] = '_';
                f = 0;
                break;
            }
        }
    }
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            if(s[i][j] != '_')
                s[i][j] = '*';
            if(s[i][j] == '_')
                s[i][j] = '8';
        }
    }
    for(int i = 0; i < 9; i++) {
        cout << s[i] << endl;
    }
} 