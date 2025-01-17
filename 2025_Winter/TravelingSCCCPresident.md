---
DONE_DATE: 2025/01/17
---

# Traveling SCCC President

## 난이도

- 골드 3

## 문제

https://www.acmicpc.net/problem/28119

## 알고리즘 분류

- 그래프 이론
- 최소 스패닝 트리
- 프림 or 크루스칼

## 정답코드

```c++
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Edge; /// weight, vertex
typedef vector<vector<Edge>> Graph;

// Prim
int prim(Graph &graph, int S) {
    vector<bool> visited(graph.size(), false);
    priority_queue<Edge, vector<Edge>, greater<>> pq;
    pq.emplace(0, S);
    int total = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total += weight;
        for (auto [w, v]: graph[u]) {
            if (!visited[v]) {
                pq.emplace(w, v);
            }
        }
    }

    return total;
}

int main() {
    int N, M, S;
    cin >> N >> M >> S;
    Graph graph(N + 1);
    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }

    cout << prim(graph, S);
}

```

## 회고

- 결국은 최소 스패닝 트리를 구하는 문제였다. 프림 알고리즘을 사용해서 풀었다.
- 회의 순서라는게 있긴하지만 순간이동이 가능해서 그냥 최소 스패닝 트리를 구하면 된다.
- 해당 알고리즘을 잘 숙지하고 있어야겠다.
- 이 문제는 당연하게도 크루스칼을 이용해서 풀 수도 있다.



