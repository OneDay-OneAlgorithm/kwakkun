#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    while (N--) {
        int num;
        cin >> num;

        if (maxHeap.size() == minHeap.size()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(maxTop);
        }

        cout << maxHeap.top() << '\n';
    }
}