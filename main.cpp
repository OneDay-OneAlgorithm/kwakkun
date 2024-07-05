#include <iostream>

#define ll long long
using lll = __int128;
using namespace std;

ll fpow(lll a, lll b, lll c) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << fpow(a, b, c) << '\n';
}