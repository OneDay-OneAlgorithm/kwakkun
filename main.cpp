#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll N, x;
    cin >> N >> x;

    vector<ll> A(N + 1);
    ll sum = 0;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        sum += A[i] * A[i];
    }

    double t = (sum == 0) ? 0 : sqrt(static_cast<double>(x) * N / sum);

    for (int i = 1; i <= N; ++i) {
        printf("%.9lf ", A[i] * t);
    }

    return 0;
}
