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