#include <bits/stdc++.h>

using namespace std;

struct Compare {
    bool operator()(pair<int, int> const &p1, pair<int, int> const &p2) {
        return p1.second > p2.second;
    }
};

int n, l;
// fisrt: index, second: value
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pq.emplace(i, x);
        while (pq.top().first <= i - l) {
            pq.pop();
        }
        cout << pq.top().second << " ";

    }

    return 0;
}