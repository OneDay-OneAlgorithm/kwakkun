#include <bits/stdc++.h>

using namespace std;

class Median {
private:
    priority_queue<int> maxHeap; // 작은 값들
    priority_queue<int, vector<int>, greater<>> minHeap; // 큰 값들
public:
    void insert(int x) {
        if (maxHeap.empty() || x <= maxHeap.top()) {
            maxHeap.push(x);
        } else {
            minHeap.push(x);
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    int query() {
        return maxHeap.top();
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;
        Median central = Median();
        vector<int> arr;
        for (int i = 1; i <= M; i++) {
            int x;
            cin >> x;
            central.insert(x);
            if (i % 2 == 1) { arr.push_back(central.query()); }
        }
        cout << arr.size() << endl;
        for (int i: arr) {
            cout << i << " ";
        }
        cout << endl;
    }
}