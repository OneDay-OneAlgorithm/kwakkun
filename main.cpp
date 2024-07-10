#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a;
    cin >> a;
    ll ans = 1;
    for (int i = 0; i < a - 2; i++) {
        ll b;
        cin >> b;
        ans = lcm(ans, b);
    }
    cout << ans;
    return 0;
}