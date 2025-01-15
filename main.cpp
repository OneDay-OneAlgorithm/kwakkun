#include <bits/stdc++.h>

using namespace std;

#define INF 1e9
typedef pair<int, int> Edge; // <weight, vertex>
typedef vector<vector<Edge>> Graph;

void dijkstra(int start, Graph &graph, vector<int> &dist, vector<int> &path) {
    priority_queue<Edge, vector<Edge>, greater<>> pq;
    pq.emplace(0, start);
    dist[start] = 0;

    while (!pq.empty()) {
        auto [weight, vertex] = pq.top();
        pq.pop();

        if (dist[vertex] < weight) continue; // 이미 더 짧은 경로로 방문한 적 있다면 무시

        for (auto &neighbor: graph[vertex]) {
            auto [w, v] = neighbor;
            if (dist[v] > dist[vertex] + w) { // 새로운 경로가 기존보다 더 짧은 경우 갱신
                dist[v] = dist[vertex] + w;
                path[v] = vertex;
                pq.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    Graph graph(n + 1);

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    vector<int> dist(n + 1, INF);
    vector<int> path(n + 1, -1);

    int start, end;
    cin >> start >> end;
    dijkstra(start, graph, dist, path);

    cout << dist[end] << '\n';

    vector<int> reverse_path;
    for (int i = end; i != -1; i = path[i]) {
        reverse_path.push_back(i);
    }

    reverse(reverse_path.begin(), reverse_path.end());

    cout << reverse_path.size() << '\n';

    for (auto i: reverse_path) {
        cout << i << ' ';
    }
}
