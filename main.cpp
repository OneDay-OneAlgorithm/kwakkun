#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Edge; // weight, destination
typedef vector<vector<Edge>> Graph;

int dijk(Graph &graph, int start, int end) {
    priority_queue<Edge, vector<Edge>, greater<>> pq;
    vector<bool> visited(graph.size(), false);
    vector<int> distance(graph.size(), INT_MAX);

    pq.emplace(0, start);
    distance[start] = 0;

    while (!pq.empty()) {
        auto [cost, des] = pq.top();
        pq.pop();

        if (visited[des]) continue;
        visited[des] = true;

        for (auto [c, d]: graph[des]) {
            if (distance[des] + c < distance[d]) {
                pq.emplace(distance[des] + c, d);
                distance[d] = distance[des] + c;
            }
        }
    }

    return distance[end];
}

int main() {
    int N;
    cin >> N;
    Graph graph;
    graph.resize(N + 1);
    int M;
    cin >> M;

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].emplace_back(c, b);
    }

    int start, end;
    cin >> start >> end;

    cout << dijk(graph, start, end);
}


