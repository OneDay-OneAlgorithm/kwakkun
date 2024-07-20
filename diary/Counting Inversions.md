---
DONE_DATE: 2024/07/20
---
https://www.acmicpc.net/problem/10090


오답코드
```c++
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<ll> v;
vector<ll> input;
vector<ll> tree;

//void init(int node = 1, int start = 0, int end = n - 1) {
//    if (start == end) {
//        tree[node] = 0;
//    } else {
//        int mid = (start + end) / 2;
//        init(node * 2, start, mid);
//        init(node * 2 + 1, mid + 1, end);
//        tree[node] = tree[node * 2] + tree[node * 2 + 1];
//    }
//}

int query(int left, int right, int node = 1, int start = 0, int end = n - 1) {
//    cout << "query => left: " << left << " right: " << right << " node: " << node << " start: " << start << " end: "
//         << end
//         << endl;
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

void update(int idx, int value, int node = 1, int start = 0, int end = n - 1) {
//    cout << "update => idx: " << idx << " value: " << value << " node: " << node << " start: " << start << " end: "
//         << end
//         << endl;
    if (idx < start || idx > end) {
        return;
    }

    if (start == end) {
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    update(idx, value, node * 2, start, mid);
    update(idx, value, node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void printTree() {
    cout << "-----printTree----- start" << endl;
    int n = tree.size();
    if (n == 0) return;

    int levels = 0;
    while ((1 << levels) - 1 < n) ++levels;

    int maxWidth = (1 << (levels - 1)) * 2 - 1; // 최하단 레벨의 노드 수에 따라 결정되는 최대 너비

    queue<int> q;
    q.push(1); // 루트 노드의 인덱스

    for (int level = 0; level < levels; ++level) {
        int levelNodes = 1 << level; // 해당 레벨의 노드 수
        int spaceBetweenNodes = maxWidth / levelNodes;
        int padding = spaceBetweenNodes / 2;

        for (int i = 0; i < padding; ++i) cout << " ";

        for (int i = 0; i < levelNodes && !q.empty(); ++i) {
            int index = q.front();
            q.pop();

            if (index < n) {
                cout << tree[index];
                q.push(2 * index); // 왼쪽 자식 인덱스
                q.push(2 * index + 1); // 오른쪽 자식 인덱스
            } else {
                cout << " ";
                q.push(n); // 자식 노드가 없을 경우 빈 노드
                q.push(n);
            }

            for (int j = 0; j < spaceBetweenNodes - 1; ++j) cout << " ";
        }
        cout << endl;
    }
    cout << "-----printTree----- end" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);
    input.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    for (int i = 1; i <= n; ++i) {
        v[i - 1] = 0;
    }

    int h = (int) ceil(log2(n));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);

//    printTree();

    int result = 0;
    for (int i = 0; i < n; i++) {
        update(input[i] - 1, 1);
//        printTree();
        int q = query(input[i], n);
//        cout << "q: " << q << endl;
        result += q;
    }

    cout << result << endl;
    return 0;
}
```

정답코드
```c++
#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n;
vector<ll> v;
vector<ll> input;
vector<ll> tree;

void init(int node = 1, int start = 0, int end = n - 1) {
    if (start == end) {
        tree[node] = 0;
    } else {
        int mid = (start + end) / 2;
        init(node * 2, start, mid);
        init(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int query(int left, int right, int node = 1, int start = 0, int end = n - 1) {
    if (left > end || right < start) {
        return 0;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    return query(left, right, node * 2, start, mid) + query(left, right, node * 2 + 1, mid + 1, end);
}

void update(int idx, int value, int node = 1, int start = 0, int end = n - 1) {
    if (idx < start || idx > end) {
        return;
    }

    if (start == end) {
        tree[node] += value;
        return;
    }

    int mid = (start + end) / 2;
    update(idx, value, node * 2, start, mid);
    update(idx, value, node * 2 + 1, mid + 1, end);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);
    input.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int h = (int) ceil(log2(n));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);

    init();

    ll result = 0;
    for (int i = 0; i < n; i++) {
        update(input[i] - 1, 1);
        result += query(input[i], n - 1);
    }

    cout << result << endl;
    return 0;
}


```

여러가지 풀이가 가능하고, 이 문제는 세그먼트 트리를 이용한 풀이로 시도해보았다.
아직 세그먼트 트리가 좀 익숙하지 않다. 
이 문제는 세그먼트 트리를 먼저 구성하고 시작하는 것이 아니라, 입력을 받으면서 세그먼트 트리를 구성하면서 문제를 풀어나가는 방식이다.
세그먼트 트리를 구성하면서, 현재 위치보다 큰 수의 개수를 세는 방식으로 문제를 풀었다.

https://barbera.tistory.com/41

해당 블로그에 있는 그림을 보면 좋다.
접근방법은 맞았는데 코드가 잘못되어서 챗지피티의 도움으로 코드를 수정해서 정답을 받았다.




