#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;cin >> n;
        if(n % 2 == 0 && (n / 2) % 2 == 0 && n > 2)   
            cout << "Bong" << endl;
        else 
            cout << "Bing" << endl;
    }
}

// 1 2 3 4 5 6 7
// A 1 2
// B 3 4
// A 5 6
// B 
// AWIN

// 1 2 3 4 5
// A 1 2
// B 4 3
// A 5
//AWIN

// 1 2 3 4 5 6
// 1 2 A
// 3 4 B
// 5 6 A
//AWIN

// 1 2 3 4 5 6 7 8
// A 1 2
// B 3 4
// A 5 6
// B 7 8
// BWIN

// 1 2 3 4 5 6 7 8 9 10 
// A 1 2
// B 2 4