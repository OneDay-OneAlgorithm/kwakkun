#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> prefixSum(N + 1, 0);
    unordered_map<ll, ll> map;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        prefixSum[i] = prefixSum[i - 1] + num;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (prefixSum[i] == K) {
            ans++;
        }
        ans += map[prefixSum[i] - K];
        map[prefixSum[i]]++;
    }
    cout << ans;
}