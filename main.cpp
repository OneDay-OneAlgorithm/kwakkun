#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<long long>> Matrix;

Matrix multiply(const Matrix &a, const Matrix &b, int mod) {
    int n = a.size();
    Matrix result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return result;
}

Matrix power(Matrix base, ll exp, int mod) {
    int n = base.size();
    Matrix result(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    while (exp > 0) {
        if (exp & 1) { // exp의 마지막 비트가 1이면 => 홀수
            result = multiply(result, base, mod);
        }
        base = multiply(base, base, mod);
        exp >>= 1;
    }
    return result;
}

int main() {
    int n;
    ll b;
    int modular = 1000;
    vector<vector<ll>> m;

    cin >> n >> b;
    m.resize(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    Matrix result = power(m, b, modular);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}