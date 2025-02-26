#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;

void floyd(vector<vector<int>> &dist, vector<vector<int>> &next, int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

vector<int> getPath(int u, int v, vector<vector<int>> &next) {
    if (next[u][v] == -1) return {};
    vector<int> path;
    int cur = u;
    while (cur != v) {
        path.push_back(cur);
        cur = next[cur][v];
    }
    path.push_back(v);
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    vector<vector<int>> next(N + 1, vector<int>(N + 1, -1));

    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    cin >> M;

    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (dist[a][b] > c) {
            dist[a][b] = c;
            next[a][b] = b;
        }
    }

    floyd(dist, next, N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) cout << "0 ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    for (int u = 1; u <= N; u++) {
        for (int v = 1; v <= N; v++) {
            if (u == v || next[u][v] == -1) {
                cout << "0\n";
            } else {
                vector<int> path = getPath(u, v, next);
                cout << path.size() << " ";
                for (int node: path) {
                    cout << node << " ";
                }
                cout << "\n";
            }
        }
    }

}