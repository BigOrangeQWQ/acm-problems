#include <iostream>

using namespace std;

string 
a= "../.\\..", 
b= "...|..." ,
c = "........",
d="../.\\/.",
e ="..\\_/\\.",
g ="..\\_/..";


int main() {
    string o, p, q, f;
    cin >> o >> p >> q >> f >> f;
    if(o == b && q == a && f == e)
        cout << 'm' << endl;
    else if(o == b && q == a && f == g)
        cout << 'p' << endl;
    else
        cout << 'o' << endl;

}

