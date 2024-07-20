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
