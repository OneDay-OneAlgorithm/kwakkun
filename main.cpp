#include <bits/stdc++.h>

#define DIV 1000000007
typedef long long ll;
using namespace std;

ll fact(int n) {
    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = (res * i) % DIV;
    }
    return res;
}

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % DIV;
        }
        a = (a * a) % DIV;
        b /= 2;
    }
    return res;
}

ll binomial(int n, int k) {
    if ((k > n) || (k < 0)) return 0;

    ll res = fact(n);
    res = (res * fast_pow(fact(k), DIV - 2)) % DIV;
    res = (res * fast_pow(fact(n - k), DIV - 2)) % DIV;
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << binomial(n, k) << endl;
}