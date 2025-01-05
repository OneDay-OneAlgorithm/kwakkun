#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pii>> graph(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<bool> visited(V + 1, false);
    priority_queue<pii, vector<pii>, greater<>> pq;

    int start = 1;
    pq.emplace(0, start);
    int total_weight = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        total_weight += w;

        for (auto [v, w]: graph[u]) {
            if (!visited[v]) {
                pq.emplace(w, v);
            }
        }
    }

    cout << total_weight;
}