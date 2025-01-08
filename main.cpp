#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

bool compare(const pii &a, const pii &b) {
    if (a.first == 0) return false;
    else if (b.first == 0) return true;
    else if (a.second == 0 && b.second == 0) return a.first < b.first;

    return b.first * a.second < a.first * b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pii> works(n);
    for (int i = 0; i < n; i++) {
        cin >> works[i].first >> works[i].second;
    }

    sort(works.begin(), works.end(), compare);

    ll totalTime = 0;

    for (auto work: works) {
        totalTime += work.first * totalTime + work.second;
        totalTime %= 40000;
    }

    cout << totalTime;
}