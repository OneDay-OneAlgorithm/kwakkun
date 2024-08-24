#include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> output;

void combination(int n, int m) {
    if (m == 0) {
        for (int i: output) {
            cout << i << ' ';
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        output.push_back(i);
        combination(n, m - 1);
        visited[i] = false;
        output.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    combination(n, m);
    return 0;
}