#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> ladder;
unordered_map<int, int> snakes;

int bfs() {
    queue<int> q;
    int depth[101];
    bool visited[101] = {false};
    fill_n(depth, 101, INT_MAX);

    q.push(1);
    depth[1] = 0;
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++) {
            int v = u + i;

            // 100칸 넘어가면 이동 X
            if (v > 100) {
                continue;
            }

            // 사다리 혹은 뱀이면 이동
            if (ladder.find(v) != ladder.end()) {
                v = ladder[v];
            } else if (snakes.find(v) != snakes.end()) {
                v = snakes[v];
            }

            // 이미 방문한 칸이면 이동 X
            if (visited[v]) {
                continue;
            }

            // 방문한 칸이 아니면 이동
            q.push(v);
            depth[v] = min(depth[v], depth[u] + 1);
            visited[v] = true;

            // 100칸에 도착하면 종료
            if (v == 100) {
                return depth[v];
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ladder.emplace(x, y);
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        snakes.emplace(u, v);
    }

    cout << bfs() << endl;
}