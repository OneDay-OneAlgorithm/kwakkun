#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    int max_v, min_v;
    if (a > b) {
        max_v = a;
        min_v = b;
    } else {
        max_v = b;
        min_v = a;
    }
    int gcd_v = gcd(max_v, min_v);
    int lcm_v = lcm(max_v, min_v);

    cout << gcd_v << '\n' << lcm_v << '\n';
}