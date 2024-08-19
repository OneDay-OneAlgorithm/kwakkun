#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    ll left = 0;
    ll right = *max_element(arr.begin(), arr.end());

//    cout << right << endl;
    int result = 0;

    while (left <= right) {
//        cout << left << " " << right << endl;

        ll mid = (left + right) / 2;
        ll cut_length = 0;

        for (int i = 0; i < N; ++i) {
            if (arr[i] > mid) {
                cut_length += arr[i] - mid;
            }
        }

        if (cut_length >= M) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}