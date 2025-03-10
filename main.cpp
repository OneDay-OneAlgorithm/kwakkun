#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll cost(int value, vector<int> &trees) {
    ll sum_of = 0;
    for (int t: trees) {
        if (t >= value) { sum_of += t - value; }
    }
    return sum_of;
}

int main() {
    int N, M;

    cin >> N >> M;
    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int left = 0;
    int right = *max_element(trees.begin(), trees.end());
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        ll ct = cost(mid, trees);
        if (ct < M) {
            right = mid - 1;
        } else if (ct >= M) {
            result = mid;
            left = mid + 1;
        }
    }

    cout << result;
}