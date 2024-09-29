#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 2e6;

int lg[maxn + 1];
int main() {
    lg[1] = 0, lg[2] = 1;
    for(int i = 3; i <= maxn; i++) {
        lg[i] = lg[i >> 1] + 1;
        if (lg[i] != floor(log2(i))) {
            cout << "diff in " << i << endl;
            exit(0);
        }
    }
    
}