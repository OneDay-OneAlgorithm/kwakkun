#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    vector<int> arr;
    int counter = 0;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    int curr = arr.size() - 1;
    while (k != 0) {
        if (arr[curr] <= k) {
            k -= arr[curr];
            counter++;
        } else {
            curr--;
        }
    }
    cout << counter;
}