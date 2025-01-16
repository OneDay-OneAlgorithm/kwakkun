#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> Edge; // weight, vertex
typedef vector<vector<Edge>> Graph;

bool bellmanFord(int start, Graph &graph, vector<ll> &dist) {
    dist[start] = 0;
    for (int i = 0; i < graph.size() - 1; i++) {
        for (int u = 0; u < graph.size(); u++) {
            for (auto &edge: graph[u]) {
                auto [w, v] = edge;
                if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 0; u < graph.size(); u++) {
        for (auto &edge: graph[u]) {
            auto [w, v] = edge;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n + 1);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
    }

    vector<ll> dist(n + 1, INT_MAX);
    if (!bellmanFord(1, graph, dist)) {
        cout << -1;
        return 0;
    }
    for (int i = 2; i < n + 1; i++) {
        cout << (dist[i] == INT_MAX ? -1 : dist[i]) << '\n';
    }
}