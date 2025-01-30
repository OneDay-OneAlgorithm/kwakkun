#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll min_val, max_val;
    cin >> min_val >> max_val;
    ll rangeSize = max_val - min_val + 1;

    // 제곱수 배수 여부를 체크할 배열(각 인덱스는 해당 범위의 한 숫자에 대응)
    vector<bool> isSquareMultiple(rangeSize, false);

    // 2 이상 sqrt(max_val) 이하의 모든 i에 대해 i^2의 배수를 체크
    for (ll i = 2; i * i <= max_val; i++) {
        ll square = i * i;

        // min_val 이상이면서 square로 나누어떨어지는 최소 시작값
        ll start = ((min_val - 1) / square + 1) * square;

        // start부터 max_val 이하까지 square씩 증가
        for (ll j = start; j <= max_val; j += square) {
            isSquareMultiple[j - min_val] = true;
        }
    }

    // 제곱수의 배수가 아닌(아직 false인) 인덱스 개수
    ll result = 0;
    for (ll i = 0; i < rangeSize; i++) {
        if (!isSquareMultiple[i]) {
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}
