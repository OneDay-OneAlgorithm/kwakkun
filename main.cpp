#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    int max_pig_v = 0;
    for (auto x: a) {
        if (x.first == "pig") max_pig_v = max(max_pig_v, x.second);
    }

    ll result = 0;
    for(auto x : a) {
        if (x.first != "pig" && x.second < max_pig_v) {
            result += x.second;
        }
    }

    cout << result + max_pig_v << endl;
}