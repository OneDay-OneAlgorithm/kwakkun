---
DONE_DATE: 2024/08/24
---

https://www.acmicpc.net/problem/15649

```c++
#include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> output;

void combination(int n, int m) {
    if (m == 0) {
        for (int i: output) {
            cout << i << ' ';
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        output.push_back(i);
        combination(n, m - 1);
        visited[i] = false;
        output.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    combination(n, m);
    return 0;
}

```

- 백트래킹을 이용하여 조합을 구현하는 문제이다.
- n과 m을 입력받고, 1부터 n까지의 수 중에서 m개를 고르는 모든 조합을 구하는 문제이다.
- visited 배열을 이용해 방문한 수를 체크하고, output 배열에 수를 넣어주고 빼주면서 조합을 구현한다.
- m이 0이 되면 output 배열에 있는 수를 출력해주면 된다.
- visited 배열과 output 배열을 초기화해주지 않아도 되는 이유는 재귀 함수가 끝나면서 visited 배열과 output 배열이 초기화되기 때문이다.
- visited 배열은 방문한 수를 체크하기 위해 사용하고, output 배열은 조합을 저장하기 위해 사용한다.
- 재귀 함수를 이용해 조합을 구현할 수 있다.



