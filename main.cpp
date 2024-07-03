#include <bits/stdc++.h>
using namespace std;
int N;
char target, A[101010];

int solve(int n, char t) {
    if (n == 1) return A[1] == t ? 0 : 1;
    if (t == 'T') {
        if (A[n] == 'T' && A[n - 1] == '&') return min(1, solve(n - 2, 'T'));
        if (A[n] == 'T' && A[n - 1] == '|') return 0;
        if (A[n] == 'F' && A[n - 1] == '&') return min(2, 1 + solve(n - 2, 'T'));
        if (A[n] == 'F' && A[n - 1] == '|') return min(1, solve(n - 2, 'T'));
    } else if (t == 'F') {
        if (A[n] == 'T' && A[n - 1] == '&') return min(1, solve(n - 2, 'F'));
        if (A[n] == 'T' && A[n - 1] == '|') return min(2, 1 + solve(n - 2, 'F'));
        if (A[n] == 'F' && A[n - 1] == '&') return 0;
        if (A[n] == 'F' && A[n - 1] == '|') return min(1, solve(n - 2, 'F'));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    cin >> target;
    cout << solve(N, target);
}