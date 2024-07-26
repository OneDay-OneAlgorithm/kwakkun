#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
typedef vector<vector<pair<int, int>>> Graph;

void dijkstra(int start, Graph &graph, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.emplace(0, start);

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_dist > dist[current_node]) continue;

        for (auto &edge: graph[current_node]) {
            int next_node = edge.first;
            int weight = edge.second;
            int new_dist = current_dist + weight;

            if (new_dist < dist[next_node]) {
                dist[next_node] = new_dist;
                pq.emplace(new_dist, next_node);
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    int start_v;
    cin >> start_v;

    Graph graph(V + 1);
    vector<int> dist(V + 1, INF);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    dijkstra(start_v, graph, dist);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }

    return 0;
}