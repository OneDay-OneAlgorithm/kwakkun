#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> WeightEdge; // first: weight, second: vertex
typedef vector<vector<WeightEdge>> Graph;

Graph graph;

int prim() {
    int startVertex = 1;
    priority_queue<WeightEdge, vector<WeightEdge>, greater<>> pq;
    vector<bool> visited(graph.size(), false);

    pq.emplace(0, startVertex);

    int totalWeight = 0;
    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;
        totalWeight += w;

        for (auto &edge: graph[u]) {
            int weight = edge.first; // weight
            int v = edge.second; // vertex
            if (!visited[v]) {
                pq.emplace(weight, v);
            }
        }
    }

    return totalWeight;
}

int main() {
    int V, E;
    cin >> V >> E;
    graph.resize(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    cout << prim();
}