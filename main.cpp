#include <bits/stdc++.h>

typedef long long ll;
#define MOD 10007
using namespace std;

ll binomial(int N, int K) {
    int old_dp[N + 1];
    int new_dp[N + 1];

    old_dp[0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j) {
                new_dp[j] = 1;
            } else {
                new_dp[j] = (old_dp[j] + old_dp[j - 1]) % MOD;
            }
        }

        for (int j = 0; j <= N + 1; j++) {
            old_dp[j] = new_dp[j];
        }
    }
    return new_dp[K];
}

int main() {
    int N, K;
    cin >> N >> K;
    cout << binomial(N, K);
}