---
DONE_DATE: 2024/08/31
---

https://www.acmicpc.net/problem/1149

```c++
#include <bits/stdc++.h>

using namespace std;

int game_map[1001][3];
int dp[1001][3];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> game_map[i][j];
        }
    }

    dp[0][0] = game_map[0][0];
    dp[0][1] = game_map[0][1];
    dp[0][2] = game_map[0][2];

    for (int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + game_map[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + game_map[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + game_map[i][2];
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});

    return 0;
}
```

dp문제.
예전에 한번 풀어본 적이 있는 문제라 수월했다.
어느덧 마지막이네?


