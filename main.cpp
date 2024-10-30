#include <bits/stdc++.h>

using namespace std;
int pSum[1025][1025] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int input;
            cin >> input;
            pSum[i][j] = pSum[i][j - 1] + input;
        }
        if (i != 1) {
            for (int j = 1; j <= n; ++j) {
                pSum[i][j] += pSum[i - 1][j];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << pSum[x2][y2] - pSum[x1 - 1][y2] - pSum[x2][y1 - 1] + pSum[x1 - 1][y1 - 1] << "\n";
    }
}