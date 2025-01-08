#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> WeightedEdge;
typedef vector<vector<WeightedEdge >> Graph;

Graph graph;

int prim() {
    int startVertex = 1;
    priority_queue<WeightedEdge, vector<WeightedEdge>, greater<>> pq;
    vector<bool> visited(graph.size(), false);

    pq.emplace(0, startVertex);

    int totalWeight = 0;
    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();
        if (visited[vertex]) continue;
        visited[vertex] = true;
        totalWeight += weight;
        for (auto [w, v]: graph[vertex]) {
            if (!visited[v]) {
                pq.emplace(w, v);
            }
        }
    }

    return totalWeight;
}

int main() {
    int V, E;
    cin >> V >> E;
    graph.resize(V + 1);
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    cout << prim() << endl;
}