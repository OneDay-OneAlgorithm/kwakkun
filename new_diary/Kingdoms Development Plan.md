---
DONE_DATE: 2024/10/09
---

# Kingdom’s Development Plan

## 문제

https://www.acmicpc.net/problem/32459

## 알고리즘 분류

- 자료 구조
- 그래프 이론
- 우선순위 큐
- 위상 정렬
- 방향 비순환 그래프

## 오답코드

```c++

```

## 정답코드

```c++
#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> Graph;

int main() {
    Graph g;
    int n, m;
    int a, b;
    cin >> n >> m;

    g.resize(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a].push_back(b);
    }

    vector<int> inDegree(g.size());
    priority_queue<int, vector<int>, greater<> > pq;
    vector<int> result;

    for (auto row: g) {
        for (auto i: row) {
            inDegree[i]++;
        }
    }

    for (int i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int i = pq.top();
//        cout << "top : " << i << endl;
        result.push_back(i);
        pq.pop();
        for (auto j: g[i]) {
            inDegree[j]--;
            if (inDegree[j] == 0) {
                pq.push(j);
            }
        }
    }

    if(result.size() != n) {
        cout << "IMPOSSIBLE";
    } else {
        for (auto i : result) {
            cout << i << " ";
        }
    }
}
```

## 회고

어제 icpc 문제를 풀면서 봤던 문제인데 내가 본 것은 아니고 해성이가 봤던 문제다.
위상정렬 문제인데 그 자리에서는 못보고
집에 와서 다시 본다.

Kahn's Algorithm 을 사용해서 위상정렬을 하면 된다.
예전에 `선수과목` 이라는 문제에서 위상정렬을 구현했었다.

간단하게 설명해서 진입차수가 0인것을 큐에 넣고
큐에 뺄때마다 그것이랑 연결된 edge의 차수를 감소시킨 후
만약 그렇게 해서 감소된 edge의 진입차수가 0이되면 큐에 넣으면 된다.

다만 이 문제는 깊이에 있는 edge의 경우에는 사전순(작은 순)으로 출력을 해야해서
우선순위 큐를 사용해서 작은게 먼저 오도록 했다.

사실 우선순위 큐를 쓴다는 아이디어는 해성이한테서 들었다.



