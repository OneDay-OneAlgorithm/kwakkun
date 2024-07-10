#include <bits/stdc++.h>

using namespace std;

int arr[1002][1002];
int visited[1002][1002];

int bfs(int x, int y) {
    queue<pair<int, int>> q;

    int control[4][2] = {
            {0,  1},
            {0,  -1},
            {1,  0},
            {-1, 0}
    };

    visited[x][y] = 0;
    q.emplace(x, y);

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (auto &c: control) {
            int next_x = cur_x + c[0];
            int next_y = cur_y + c[1];

            if (arr[next_x][next_y] != 1) {
                continue;
            }

            if (visited[next_x][next_y] == 0) {
                visited[next_x][next_y] = visited[cur_x][cur_y] + 1;
                q.emplace(next_x, next_y);
            }
        }
    }
    return 0;
}

int main() {
    int n, m;
    int start_x = 0, start_y = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                start_x = i;
                start_y = j;
            }
        }
    }

    bfs(start_x, start_y);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(arr[i][j] == 2){
                cout << 0 << " ";
                continue;
            }
            if (arr[i][j] != 0 && visited[i][j] == 0) {
                cout << -1 << " ";
                continue;
            }
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}