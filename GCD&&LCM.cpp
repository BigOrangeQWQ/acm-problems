// int gcd(int a, int b) {
//     if(b == 0)
//         return a;
//     return gcd(b, a % b);
// }

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return gcd(a, b) * a * b;
}